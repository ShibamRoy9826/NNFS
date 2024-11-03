#include "classes.h"
#include <iostream>
#include <random>
#include <vector>
using std::vector;

template class Matrix<double>;


template <typename T> Matrix<T>::Matrix (int rows, int cols)
{
  rows = rows;
  cols = cols;
  data.resize (rows, vector<T> (cols));
}

template <typename T>
void
Matrix<T>::display ()
{
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          std::cout << data[i][j] << " ";
        }
      std::cout << std::endl;
    }
}

template <typename T>
int
Matrix<T>::getCol ()
{
  return cols;
}

template <typename T>
int
Matrix<T>::getRow ()
{
  return rows;
}

template <typename T>
void
Matrix<T>::setRandom (int lower, int upper)
{
  std::random_device r;
  std::mt19937 generator (r ());
  std::uniform_real_distribution<T> distribution(lower, upper);

  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          data[i][j] = distribution(generator);
        }
    }
}

template <typename T>
void
Matrix<T>::setVal (int val)
{
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          data[i][j] = val;
        }
    }
}

template <typename T>
void
Matrix<T>::setData (vector<vector<T> > vec)
{
  rows = vec.size ();
  cols = vec[0].size ();
  data.resize (rows, vector<T> (cols));

  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          data[i][j] = vec[i][j];
        }
    }
}

template <typename T>
void
Matrix<T>::resize (int row, int col)
{
  rows = row;
  cols = col;
  data.resize (rows, vector<T> (cols));
}

template <typename T>
Matrix<T>
Matrix<T>::transpose ()
{
  Matrix<T> transposed (cols, rows);
  
  vector<vector<T>> vec(cols, vector<T>(rows));

  for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
        {
          vec[j][i] = data[i][j];
        }
    }
  transposed.setData(vec);
  return transposed;
}

template <typename T>
void
Matrix<T>::add (vector<T> vec)
{
  for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
        {
          data[i][j] += vec[j];
        }
    }
}

template <typename T>
void
Matrix<T>::add (vector<vector<T> > vec)
{
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          data[i][j] += vec[i][j];
        }
    }
}
