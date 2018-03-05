#include<iostream>
#include<ctime>
#include<Eigen/Core>
#include<Eigen/Dense>

using namespace std;

#define MATRIX_SIZE 100

//本程序演示了使用QR分解和Cholesky分解的方法对方程组进行求解
int main(int argc, char** argv)
{
  Eigen::Matrix< double, MATRIX_SIZE, MATRIX_SIZE > A;
  A = Eigen::MatrixXd::Random( MATRIX_SIZE, MATRIX_SIZE);
  Eigen::Matrix<double, MATRIX_SIZE, 1> b;
  b = Eigen::MatrixXd::Random(MATRIX_SIZE,1);
  Eigen::Matrix< double, MATRIX_SIZE, 1> x1;
  Eigen::Matrix< double, MATRIX_SIZE, 1> x2;

//Qr分解
  clock_t time1 = clock();
  x1 = A.colPivHouseholderQr().solve(b);
  cout <<"Time use in Qr compsition is " << 1000*(clock() - time1)/(double)CLOCKS_PER_SEC << "ms" << endl;
  
//Cholesky分解
  clock_t time2 = clock();
  x2 = A.llt().solve(b);
  cout <<"Time use in Cholesky compsition is " << 1000*(clock() - time2)/(double)CLOCKS_PER_SEC << "ms" << endl; 
  return 0;
}
