echo "Starting building..."
rm $1/main.exe || true
cmp --silent $1/main.cpp /tmp/testbuild
if [ ! -f $1/main.cpp ]; then
    echo "main.cpp not found!"
    exit 1
fi
if [ ! -f $1/main.exe ]; then
    g++ -g $1/main.cpp -o $1/main.exe
    cp $1/main.cpp /tmp/testbuild
fi
if [ $? -ne 0 ]; then 
    g++ -g $1/main.cpp -o $1/main.exe
    cp $1/main.cpp /tmp/testbuild
fi