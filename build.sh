cd build
echo "Building for Raspberry Pi..."
rm -f *
cmake .. -DCMAKE_TOOLCHAIN_FILE=../rpi-toolchain.cmake
make
echo "Done!"