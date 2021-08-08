#include <iostream>
#include "body.h"

std::string body[6] = { "/", "\\", "/", "\\", "|", "o" };

int count = 0;

void remove_part() {
  body[count] = " ";

  count++;
}

void print_body() {
  std::cout << " " << body[5] << std::endl;
  std::cout << body[2] << body[4] << body[3] << std::endl;
  std::cout << body[0] << " " << body[1] << std::endl;
}
