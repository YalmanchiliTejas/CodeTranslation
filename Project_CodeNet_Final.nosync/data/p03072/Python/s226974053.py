N = int(input())
H = list(map(int, input().split()))

counter = 1
max_num = H[0]

for i in range(N-1):
    if max_num <= H[i+1]:
        counter += 1
    max_num = max(max_num, H[i+1])
print(counter)
