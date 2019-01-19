#include <cstdlib>
#include <iostream>
#include <string>

std::string CaesarCipher(std::string string, int shift, bool cipher);

int main(){
  std::string string = "";
  std::string shiftAmount = "";
  int iShiftAmount;
  std::cout << "Type :q to exit" << std::endl;
  while(1){
    std::cout << " ? : ";
    std::getline(std::cin, string);
    std::cout << "Shift amount: ";
    std::getline(std::cin, shiftAmount);
    iShiftAmount = stoi(shiftAmount);
    if(string == ":q") break;

    std::string encipherdStr = CaesarCipher(string, iShiftAmount, true);
    std::string decipheredStr = CaesarCipher(encipherdStr, iShiftAmount, false);
    std::cout << "Enciphered: " << encipherdStr << "\nDeciphered: " << decipheredStr << std::endl;
  }
  std::cout << "Exiting";
  return 0;
}

std::string CaesarCipher(std::string string, int shift, bool cipher){
  const int nAlphabet = 26;
  std::string result;

  if(!cipher) shift = nAlphabet - shift;
  for(int i = 0; i < string.size(); ++i){
    if(isspace(string[i])) result += ' ';
    else if(islower(string[i])) result += char(((int)string[i] - (int)'a' + shift) % nAlphabet + (int)'a');
    else if(isupper(string[i])) result += char(((int)string[i] - (int)'A' + shift) % nAlphabet + (int)'A');
  }
  return result;
}
