# ABC124B - Great Ocean View
n = int(input())
data = list(map(int, input().rstrip().split()))
count = 1

for i in range(1, n):
    if data[i] == max(data[:i + 1]):
        count += 1
    
print(count)