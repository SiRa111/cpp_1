# Vehicle Rental Project

A simple C++ console application to manage vehicle rentals, allowing users to add, remove, and rent cars and bikes.

## Features

- **Add Vehicles:** Add Cars or Bikes with details such as ID, brand, model, year, rental price, availability, and specific attributes (seats for cars, engine capacity for bikes).
- **Remove Vehicles:** Remove vehicles from the system using their ID.
- **Rent Vehicles:** Rent available vehicles and mark them as unavailable.
- **View Vehicle Info:** Display full details of vehicles before renting or removing.

## Technologies

- **Language:** C++
- **Concepts:** Object-Oriented Programming, Inheritance, Polymorphism, Pointers, Vectors

## Classes

- **Vehicle (Base Class):** Stores common attributes like ID, brand, model, year, rental price, and availability.  
- **Car (Derived Class):** Adds number of seats.  
- **Bike (Derived Class):** Adds engine capacity.  

## Usage

1. Compile the code:
   ```bash
   g++ main.cpp -o rental
