# Credit Card Validator

This C program checks the validity of credit card numbers using the Luhn algorithm. It identifies whether the credit card is a VISA, American Express, or MasterCard based on certain conditions.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
- [How to Compile](#how-to-compile)
- [Contributing](#contributing)
- [License](#license)

## Features

- Validates credit card numbers using the Luhn algorithm.
- Identifies the type of credit card: VISA, American Express, or MasterCard.
- Handles credit card numbers of varying lengths.

## Requirements

- C compiler (e.g., GCC)

## Usage

1. Compile the program.
2. Run the compiled executable.
3. Enter the credit card number when prompted.
4. View the output, which indicates whether the credit card is valid and its type.

## How to Compile

1. Open a terminal.
2. Navigate to the directory containing the source code.

    ```bash
    cd path/to/source/code
    ```

3. Compile the program using a C compiler (e.g., GCC).

    ```bash
    gcc -o credit_card_validator credit_card_validator.c -lm
    ```

4. Run the compiled executable.

    ```bash
    ./credit_card_validator
    ```

## Contributing

If you'd like to contribute to this project, please follow these guidelines:

1. Fork the repository on GitHub.
2. Make changes and commit to your fork.
3. Submit a pull request with a detailed explanation of your changes.

## License

This project is licensed under the [MIT License](LICENSE).
