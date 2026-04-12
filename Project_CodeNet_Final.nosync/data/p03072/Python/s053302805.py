N = int(input())
H = [int(i) for i in input().split()]
count = 1
for i in range(1,N,1):
    if(max(H[:i])<=H[i]):
        count = count + 1
print(count)