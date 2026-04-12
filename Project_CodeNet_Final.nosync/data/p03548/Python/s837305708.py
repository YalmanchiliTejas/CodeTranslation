import sys;
lines = sys.stdin.readlines();

#配列の宣言
stdIn = {};

for i, line in enumerate(lines):
    #値を受け取り格納
    chairSize,humanSize,spaceSize = map(int, line.split());

total = 0;
maxSize = 0;
while total*(humanSize)+(total-1)*(spaceSize)+spaceSize*2 <= chairSize:
    total = total+1;
print (total-1);
