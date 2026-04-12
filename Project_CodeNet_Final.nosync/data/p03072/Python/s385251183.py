N = int(input())
H = list(map(int,input().split()))

NH = 1
for i in range(N-1):
    if H[i+1] >= max(H[0:i+1]):
        NH = NH + 1
    else:
        NH = NH

print(NH)