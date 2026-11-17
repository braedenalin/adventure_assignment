#pragma once

// One scene of the story and the doors leading out of it.
//
// RULES (do not change):
//   - Keep every member variable, name, and signature exactly as written.
//   - choices_ must stay a double pointer: Scene<T>** choices_.
//   - No std::vector, no std::array, no fixed-size array like choices_[3].
//   - The scene OWNS data_ and every scene its slots point to.
template <typename T>
class Scene {
private:
    T* data_;
    Scene<T>** choices_;
    int numChoices_;

public:
    static const int MAX_CHOICES = 3;

    Scene(T* data, int numChoices) : data_(data), choices_(nullptr), numChoices_(numChoices) {
        // TODO 1:

        // Put exact number of pointer slots
        // ending is 0 so we don't need an array
        if (numChoices_ > 0) { choices_ = new Scene<T>*[numChoices_]; }

        // Set every slot to nullptr before adding children
        for (int i = 0; i < numChoices_; i++) { choices_[i] = nullptr; }

    }

    ~Scene() {
        // TODO 2:
        // Free everything this scene owns.
        // Think about what it owns, and what each slot points to.

        // delete data
        delete data_;

        // delete everything that still exists
        if (choices_ != nullptr) {
            for (int i = 0; i < numChoices_; i++) { delete choices_[i]; }

            delete[] choices_;
        }
    }

    T* getData() const {
        return data_;
    }

    int getNumChoices() const {
        return numChoices_;
    }

    // TODO 3: true if this scene is an ending.
    bool isEnding() const {
        // return whether there are 0 choices left
        return numChoices_ == 0;
    }

    // TODO 4: the scene behind slot index.
    // Return nullptr if index is not a real slot.
    Scene<T>* getChoice(int index) const {
        // return nullptr if index is not a real slot
        if (index < 0 || index >= numChoices_) { return nullptr; }

        return choices_[index];
    }

    // TODO 5: put next into slot index.
    // Do nothing if index is not a real slot.
    void setChoice(int index, Scene<T>* next) {
        // Only does something for valid indexes
        if (index >= 0 && index < numChoices_) {
            choices_[index] = next;
        }
    }
};
