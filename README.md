# Supreme-Supplier

This is a Supplier Selection System which is a command-line program written in C++ that helps in selecting the best supplier based on various criteria. It utilizes concepts of object oriented programming and exception handling for different types of suppliers and calculate their scores.

## Table of Contents
- [Features](#features)
- [Error Handling](#error-handling)
- [Usage](#usage)
- [Dependencies](#dependencies)
- [Acknowledgment](#acknowledgment)

## Features

1. Error Handling: The code incorporates comprehensive error handling mechanisms to handle various invalid inputs. It validates user inputs at multiple points and provides appropriate error messages for incorrect values.

2. Supplier Data Input: The program prompts the user to enter the number of suppliers and then collects supplier data, including name, delivery time, order accuracy, product quality, lead time, pricing, and special discount (if applicable). It validates each input and ensures correct data entry.

3. Supplier Class and Inheritance: The code includes a base `Supplier` class and a derived `PreferredSupplier` class, demonstrating inheritance. The `PreferredSupplier` class extends the functionality of the base class by adding a special discount feature.

4. Polymorphism: The program uses polymorphism by defining virtual functions in the base `Supplier` class (`calculateScore()` and `displayDetails()` ) and overriding them in the derived `PreferredSupplier` class.

5. Score Calculation: The `calculateScore()` function calculates the score for each supplier based on the given weights for different metrics. The derived 'PreferredSupplier' class overrides this function to include the special discount.

6. Finding the Best Supplier: The `findBestSupplier()` function iterates over the list of suppliers, calculates their scores, and identifies the supplier with the lowest score as the best supplier.

7. Weight Validation: The program ensures that the weights for each metric sum up to 1. If the sum is not 1, it prompts the user to enter the weights again.

8. Improved Console Interaction: The code handles input errors gracefully and provides clear error messages. It also prevents the console from closing immediately after execution by waiting for the user to press a key before exiting.

9. Memory Management: The code properly manages memory by dynamically allocating memory for supplier objects and deallocating them before program termination.

Overall, the code incorporates error handling, inheritance, polymorphism, and ensures correct data input and output, providing a robust and user-friendly supplier selection system.

## Error Handling 

The code includes an error handling mechanism to catch and handle various types of runtime errors and exceptions. It ensures that the program gracefully handles erroneous input and provides meaningful error messages to the user. Here are the main aspects of the error handling mechanism:

1. Invalid Number of Suppliers:When the user is prompted to enter the number of suppliers, the code checks if the entered value is a positive integer. If an invalid value is entered, such as a negative number or a non-integer value, an exception of type `std::runtime_error` is thrown with an error message indicating the invalid input. The program displays the error message and prompts the user to enter a valid number of suppliers.

2. Invalid Supplier Data:For each supplier, the code validates the input data to ensure it meets the required criteria. For example, the order accuracy and product quality values should be between 0 and 1. If the user enters invalid values, such as a negative number or a value greater than 1, the code displays an error message and prompts the user to enter a valid value.

3. Invalid Weights:After entering the supplier data, the user is prompted to enter the weights for each metric. The code checks if the sum of the weights is equal to 1. If the sum is not equal to 1, an exception of type `std::runtime_error` is thrown with an error message indicating the invalid weights. The program displays the error message and prompts the user to enter valid weights.

4. Invalid Special Discount:If a supplier has a special discount, the code checks if the entered value is between 1 and 100 (inclusive). If an invalid value is entered, an exception of type `std::runtime_error` is thrown with an error message indicating the invalid special discount. The program displays the error message and prompts the user to enter a valid value.

5. Displaying Error Messages:When an error occurs, the code displays an error message on the console using `std::cerr` to indicate the issue to the user. The program then continues execution and allows the user to re-enter the correct input.

The error handling mechanism allows the program to recover gracefully from errors. Instead of abruptly terminating, it provides clear error messages and allows the user to enter valid input without losing the current progress.The error handling mechanism implemented in this code enhances its reliability, user-friendliness, and robustness. It ensures that potential runtime errors and invalid inputs are handled effectively, providing a smoother experience for users.

## Usage

1. Clone the repository: Clone the repository containing the code from GitHub to your local machine using a Git client or by downloading the ZIP file.

2. Set up your development environment: Ensure you have a C++ compiler installed on your system, such as GCC or Clang. Set up your preferred Integrated Development Environment (IDE) or text editor to write and compile C++ code.

3. Open the code: Open the 'supplier-analyser.cpp' file in your C++ development environment.

4. Review the code: Take a few moments to review the code and understand its structure and functionality. Pay attention to the class definitions, function implementations, and the overall flow of the program.

5. Run the code: Compile the code using your C++ compiler. Run the compiled executable file.

6. Follow the prompts: The program will prompt you to enter the number of suppliers and then collect data for each supplier, including name, delivery time, order accuracy, product quality, lead time, pricing, and special discount (if applicable). Enter the requested information for each supplier.

7. Enter the weights: After entering the supplier data, the program will prompt you to enter weights for each metric. The sum of the weights should be 1. Provide the desired weights for each metric.

8. View the best supplier: Once you have entered all the data and weights, the program will calculate the best supplier based on the given weights and display the details of the best supplier, including name, delivery time, order accuracy, product quality, lead time, and pricing.

9. Review the results: Take note of the best supplier and their attributes as displayed by the program.

10. Repeat or modify: If desired, you can run the program again to input different supplier data or modify the code to add additional features or customizations based on your requirements.


## Dependencies

- C++ compiler supporting C++11 or higher.

## Acknowledgment

This program was developed as an solution for a supplier selection optimization for saving costs using C++. It also demonstrates the use of object oriented programming principals, data structures and exception handling techniques in C++ programming.

