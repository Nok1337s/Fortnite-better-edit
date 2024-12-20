# Fortnite 0-Delay Script

This script provides a **0-delay keybind remap**, allowing you to simulate pressing one key by pressing another. It's highly responsive, lightweight, and simple to use. 

### How It Works
The script uses Windows API functions to detect when a specific key (e.g., `F`) is pressed and simulates the press and release of another key (e.g., `P`). This setup allows for fast and seamless input remapping, perfect for use cases like gaming.

### Features
- **Zero Delay**: The script runs with minimal delay (`10 ms`) to ensure near-instantaneous response.
- **Customizable Keybinds**: Easily change the key mappings in the script.
- Lightweight and easy to run.

### Usage Instructions
1. Download and compile the script in any C++ IDE that supports Windows API (e.g., Visual Studio).
2. Run the compiled program.
3. Press the `F` key to simulate a `P` key press.
   - Holding `F` keeps `P` pressed.
   - Releasing `F` releases `P`.

### Customization
To change the keybinds:
1. Open the script in your C++ IDE.
2. Locate the following lines in the `main` function:
   ```cpp
   if (isKeyPressed('F')) {
       sendKeyDown('P');
   }
   ```
3. Replace `'F'` with your desired input key and `'P'` with your desired output key.
   - Use [Virtual-Key Codes](https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes) for the keys.

### Disclaimer
This script is provided for educational purposes only. Using it in online games may violate their terms of service. Use responsibly.
