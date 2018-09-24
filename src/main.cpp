#include <iostream>
#include <tuple>
#include "Matrix.h"

int main(){
	
  Matrix<int, 0> m;    
  
  for(int i=0; i<10; i++)
    m[i][i] = i;
  
  for(int i=0; i<10; i++)
    m[0+i][9-i] = 9-i;
  
  for(int i=1; i<9; i++){
    for(int j=1; j<9; j++){
      std::cout << m[i][j] << ' ';
    }
    std::cout << '\n';
  }
  
  std::cout << "size: " << m.size() << '\n';

  for(const auto& e: m){
    const int x = e.first.first;
    const int y = e.first.second;
    const int v = e.second;
    std::cout << x << ' ' << y << ' ' << v << '\n';
  }

  return 0;
}
