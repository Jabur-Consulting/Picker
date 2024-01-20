# Picker Class for Arduino

## Overview

The `Picker` class is designed for Arduino projects that require random number generation with repetition prevention. It is particularly useful in scenarios where you need to generate random numbers within a specified range while avoiding immediate repetition of the same numbers.

## Features

- **Unique Random Number Generation:** Generates random numbers within a given range without immediate repetition.
- **History Tracking:** Maintains a history of recent numbers to avoid repetition.
- **Customizable Range and History Size:** Allows setting the range of random numbers (`pickQuantity`) and the history size (`pickHistorySize`) during instantiation.
- **Array Initialization:** Provides a method to initialize or reset the history array.
- **Individual History Access:** Enables access to specific history items.
- **Getter Methods:** Methods to retrieve the current `pickQuantity` and `pickHistorySize`.

## Installation

1. Place the `Picker.h` file in the same directory as your Arduino sketch.
2. Include the class in your sketch with `#include "Picker.h"`.

## Usage

### Initialization

Create an instance of the `Picker` class:

```cpp
#include "Picker.h"

Picker myPicker(10, 5); // Range of 10, history size of 5
```

### Array Initialization

Automatically initialized upon instantiation. Can be reinitialized if needed:

```cpp
myPicker.initializeArray();
```

### Generating Random Numbers

Generate a random number within the specified range:

```cpp
int randomIndex = myPicker.getRandomIndex();
```

### Accessing and Printing History

Retrieve an individual history item:

```cpp
int pick = myPicker.getPickAt(index);
```

Print the history of picks:

```cpp
myPicker.printPicks(Serial);
```

### Getting Current Configuration

Retrieve the current range and history size:

```cpp
int currentRange = myPicker.getPickQuantity();
int currentHistorySize = myPicker.getPickHistorySize();
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

  Serial.print("Range: ");
  Serial.println(myPicker.getPickQuantity());
  Serial.print("History Size: ");
  Serial.println(myPicker.getPickHistorySize());
}

void loop() {
  int randomIndex = myPicker.getRandomIndex();
  Serial.print("Random Index: ");
  Serial.println(randomIndex);

  Serial.print("Pick History: ");
  myPicker.printPicks(Serial);

  delay(2000);
}
```

## Notes

- Ensure `randomSeed()` is called in the `setup()` for effective randomization.
- The `initializeArray()` method can be used to reset the history.

## License

This `Picker` class is open-source and can be freely used and modified in both personal and commercial projects.