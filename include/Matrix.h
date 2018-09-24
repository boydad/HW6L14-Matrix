#pragma once

#include <unordered_map>

 
template <typename T, T defaulVal>
class Matrix{
  using Point = std::pair<int, int>;
  
  struct PointHash{
    size_t operator()(const Point& p) const noexcept{
      size_t hash = 17;
      const size_t mult = 23;
      hash = hash*mult + p.first;
      hash = hash*mult + p.second;
      return hash;
    };
  };
 
  
  class MatrixElement{
    Matrix<T, defaulVal>& matrix;
    
  public:
    MatrixElement(Matrix<T, defaulVal>& matrix): 
          matrix(matrix){};
    
    auto& operator=(const T& other){
      if(other == defaulVal)
        matrix.data.erase(matrix.index);
      else
        matrix.data[matrix.index] = other;
      return *this;
    }
    
    operator T() {
      const auto it = matrix.data.find(matrix.index);  
      return it == matrix.data.end() ? defaulVal : it->second;
    }
  };
  
  
  class MatrixRow{ 
    Matrix<T, defaulVal>& matrix;
    
  public:
    MatrixRow(Matrix<T, defaulVal>& matrix): 
          matrix(matrix) {};
    
    auto operator[](const int columNum){  
      matrix.index.second = columNum;
      return matrix.element;
    }
  };
  
  
  std::unordered_map<Point, T, PointHash> data;
  MatrixRow helper;
  MatrixElement element;
  std::pair<int, int> index;
  
  public:
    
    Matrix(): helper(*this), element(*this){};
    
    Matrix(const Matrix& other): Matrix() {
      data = other.data;
    }
    
    Matrix(const Matrix&& other): Matrix(){
      data = std::move(other.data);
    }
    
    Matrix& operator=(const Matrix& other){
      if(this != &other){
        this->data = other.data;
      }
      return *this;
    }
    
    Matrix& operator=(const Matrix&& other){
      if(this != &other){
        this->data = std::move(other.data);
      }
      return *this;
    }
    
    ~Matrix() = default;        
    
    auto& operator[](const int rowNum){      
      index.first = rowNum;
      return this->helper;
    }
    
    auto begin(){
      return std::begin(data);
    }
    
    auto end(){
      return std::end(data);  
    }
    
    int size(){
      return data.size();
    }
    
};