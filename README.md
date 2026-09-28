# Infix to Postfix Converter (C++)

A simple C++ program that converts an **infix expression** (e.g. `A+B*C`) into its **postfix (Reverse Polish) notation** (e.g. `ABC*+`) using a **stack implemented from scratch with a linked list**.

Built as a Data Structures practice project.

## Features

- Custom `Node` and `Stack` classes (linked-list based, no STL stack)
- Supports operators: `+`  `-`  `*`  `/`  `%`  `^`
- Supports parentheses `( )`
- Correct operator precedence and associativity (`^` is right-associative, all others are left-associative)
- Operands can be letters (`a-z`, `A-Z`) or digits (`0-9`)
- Spaces in the input are ignored

## Operator Precedence

| Operator | Precedence | Associativity |
|----------|------------|---------------|
| `^`      | 3 (highest) | Right |
| `*` `/` `%` | 2 | Left |
| `+` `-`  | 1 | Left |
| `(`      | 0 | - |

## How It Works

1. Scan the infix expression from left to right.
2. If the character is an **operand**, append it directly to the output.
3. If it is `(`, push it onto the stack.
4. If it is `)`, pop from the stack to the output until `(` is found, then discard the `(`.
5. If it is an **operator**, pop operators from the stack to the output while they have higher precedence (or equal precedence for left-associative operators), then push the current operator.
6. After the scan, pop all remaining operators from the stack to the output.

## Project Structure

```
.
├── InFix_To_PostFix.cpp   # Full source code
└── README.md
```

## Getting Started

### Prerequisites

- A C++ compiler (g++, clang, or MSVC)

### Compile

```bash
g++ InFix_To_PostFix.cpp -o infix_to_postfix
```

### Run

```bash
./infix_to_postfix        # Linux / macOS
infix_to_postfix.exe      # Windows
```

## Example Usage

```
 enter infix expression = A+B*C

 postfix = ABC*+
```

More examples:

| Infix | Postfix |
|-------|---------|
| `A+B*C` | `ABC*+` |
| `(A+B)*C` | `AB+C*` |
| `A-B-C` | `AB-C-` |
| `A^B^C` | `ABC^^` |
| `A*(B+C)/D` | `ABC+*D/` |

## Limitations

- Operands are **single characters** only (multi-digit numbers like `12` are treated as separate operands `1` and `2`).
- Unary operators (e.g. `-A`) are not supported.
- No validation for mismatched parentheses or invalid expressions.

## Possible Improvements

- Support multi-digit numbers and decimals
- Add input validation and error messages
- Add postfix evaluation
- Support unary operators

## License

This project is open source and free to use for learning purposes.
