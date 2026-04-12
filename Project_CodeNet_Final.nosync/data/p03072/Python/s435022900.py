N = int(input())
H = list(map(int,input().split()))

count =1
maximum= H[0]
for i in range (N-1):
    if H[i+1]>=maximum:
        count +=1
        maximum = H[i+1]
print(count)