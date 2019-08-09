# math-expr-evaluator
A function implemented in C++ that evaluates a arithmetic expression. This function has support for " + " , " - " , " * " , " / " operators. This function also supports unary operators. You can change operator precedence using () in expresssion.

## Installing
- Download both files math-expr-evaluator.h and math-expr-evaluator.cpp and put it into your project directory.
- #include "math-expr-evaluator.h" in your main file.
- Compile using g++ math-expr-evaluator.cpp "your_file_name.cpp"
- - ##### Ex: g++ math-expr-evaluator.cpp test.cpp

## Testing
- See [test.cpp](test.cpp) for more information.
- ### Examples
- Some arithmetic expressions and their outputs using eval function
- - 2 * - 3 * - 3 + 2 - (-1) = 21
- - 2 + 2 - 2 * (-2) + 2 * -1 + 2 / 3 * - 2 = 4.66667
- - 2 - 5 * 10 - ( 10 - 5 * 3) + ( 2 * -1 + 3 ) = -42
