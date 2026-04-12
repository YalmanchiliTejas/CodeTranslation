N = int(input())
H = list(map(int, input().split()))
count = 1
for i in range(1,N) :
    Hi = H[i]
    Ht = H[0:i]
    m = max(Ht)
    if Hi >= m :
        count += 1
print(count)