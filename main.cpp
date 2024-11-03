#include "classes.h"
#include <iostream>

using std::cout;
using std::endl;

int main () {
  // Definition and declaration
  Matrix<double> m(3,4);
  std::vector<std::vector<double>> v {
    {0.123,1.123,0.51,0.67},
    {0.123,1.123,0.51,0.67},
    {0.123,1.123,0.51,0.67},
    {0.123,1.123,0.51,0.67},
  };
  
  // Calling Some functions from this matrix obj
  m.setData(v);
  cout<<"Some basic info about the matrix: "<<endl;

  
  m.display();

  //Printing transposed matrix
  cout<<endl<<"Now for the transposed Matrix:"<<endl;
  Matrix<double> m_t=m.transpose();
  m_t.display();

  // Printing Matrix once again, after resetting random values
  cout<<endl<<"Resetting to random values"<<endl;
  m.setRandom(0, 1);
  m.display();


  return 0;
}
