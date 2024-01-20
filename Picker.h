// Picker.h

#ifndef PICKER_H
#define PICKER_H

class Picker {
private:
  int pickQuantity;
  int pickHistorySize;
  int* lastPick;  // Pointer to dynamically allocated array

public:
  // Constructor with parameters to set pickQuantity and pickHistorySize
  Picker(int _pickQuantity, int _pickHistorySize)
    : pickQuantity(_pickQuantity), pickHistorySize(_pickHistorySize) {
    lastPick = new int[pickQuantity];  // Dynamically allocate the array
    initializeArray();
    //randomSeed(analogRead(0)); // does not work before setup
  }

  ~Picker() {
    delete[] lastPick;  // Free the dynamically allocated memory
  }

  void initializeArray() {
    for (int i = 0; i < pickQuantity; i++) {
      lastPick[i] = -1;
    }
  }

  int getRandomIndex() {
    int randomIndex;
    bool isUnique;

    do {
      randomIndex = random(0, pickQuantity);
      isUnique = true;
      for (int i = 0; i < pickHistorySize; i++) {
        if (lastPick[i] == randomIndex) {
          isUnique = false;
          break;
        }
      }
    } while (!isUnique);

    updateLastPick(randomIndex);
    return randomIndex;
  }

  void updateLastPick(int newIndex) {
    for (int i = pickQuantity - 1; i > 0; i--) {
      lastPick[i] = lastPick[i - 1];
    }
    lastPick[0] = newIndex;
  }

  int getLastPick() {
    return lastPick[0];
  }

  int getPickAt(int index) {
    if (index >= 0 && index < pickHistorySize) {
      return lastPick[index];
    } else {
      // Return an error value or handle it appropriately
      return -1;
    }
  }

  // New method to get the value of pickQuantity
  int getPickQuantity() const {
    return pickQuantity;
  }

  // New method to get the value of pickHistorySize
  int getPickHistorySize() const {
    return pickHistorySize;
  }

  void printPicks(Stream& s) {
    for (int i = 0; i < pickQuantity; i++) {
      if (i == pickHistorySize) s.print("| ");
      s.print(lastPick[i]);
      s.print(" ");
    }
    s.println();
  }
};

#endif  // PICKER_H
