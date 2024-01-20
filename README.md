C++ Picker Class for Arduino

## Overview

The `Picker` class is designed for Arduino projects requiring random number generation with repetition control. It's ideal for scenarios where you need to generate random numbers within a specified range and avoid repeating recent selections.

## Features

- **Unique Random Number Generation:** Generates non-repeating random numbers within a specified range.
- **History Tracking:** Maintains a record of recent random numbers to prevent immediate repetition.
- **Customizable Range and History Size:** Set the range of random numbers and the history size when creating an instance.
- **Array Initialization:** Separate method to initialize or reset the history array.
- **Access to History:** Method to access individual history items.

## Installation

1. Place the `Picker.h` file in the same directory as your main Arduino sketch.
2. Include the `Picker` class in your sketch with `#include "Picker.h"`.

## Usage

### Initialization

Instantiate the `Picker` class with the desired range and history size:

```cpp
#include "Picker.h"

Picker myPicker(10, 5); // Range of 10, history size of 5
```

### Array Initialization

The history array is automatically initialized when the `Picker` instance is created. If needed, you can reinitialize the array:

```cpp
myPicker.initializeArray(); // Reinitializes the history array
```

### Generating Random Numbers

Generate a random number within the specified range using `getRandomIndex()`:

```cpp
int randomIndex = myPicker.getRandomIndex();
```

### Accessing History

Retrieve an individual history item:

```cpp
int pickAtIndex = myPicker.getPickAt(index);
```

### Printing the Pick History

Print the history of picks to a `Stream` object like `Serial`:

```cpp
myPicker.printPicks(Serial);
```

### Example Sketch

```cpp
#include "Picker.h"

const int range = 10;
const int historySize = 5;
Picker myPicker(range, historySize);

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  int randomIndex = myPicker.getRandomIndex();
  Serial.print("Random Index: ");
  Serial.println(randomIndex);

  Serial.println("Pick History:");
  for (int i = 0; i < historySize; i++) {
    Serial.println(picks[i]);
  }

  delay(2000);
}
```

## Notes

- It's important to call `randomSeed()` in the `setup()` function for proper random number generation.
- The `initializeArray()` method can be used to reset the history at any point during program execution.

## License

The `Picker` class is open-source and can be freely used and modified in personal or commercial projects.

---

This README provides a comprehensive guide for using the updated `Picker` class. Feel free to modify or expand it as needed for your project's documentation.
