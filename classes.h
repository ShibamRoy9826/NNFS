#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <vector>

template <typename T> class Matrix
{
private:
  std::vector<std::vector<T>> data;
  int rows;
  int cols;

public:
  Matrix (int rows, int cols);
  void display ();
  int getCol ();
  int getRow ();
  void setRandom (int lower, int upper);
  void setVal (int val);
  void setData (std::vector<std::vector<T> > vec);
  void resize (int row, int col);
  Matrix transpose ();
  void add (std::vector<T>);
  void add (std::vector<std::vector<T> >);
};

#endif
