import sys
N = int(input())
array = list(map(int,input().split()))

if not ( 1 <= N <= 20 ): sys.exit()
ceil = 0
count = 0
for I in array:
    if not ( 1 <= I <= 100 ): sys.exit()
    if I >= ceil: 
        ceil = I
        count += 1
print(count)