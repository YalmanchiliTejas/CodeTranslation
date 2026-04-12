n = int(input())

print("0:")

for b in range(1,2**n):
    a = bin(b)[2:]
    a = a[::-1]
    ans = []
    for i in range(len(a)):
        if a[i] == "1":
            ans.append(i)
    ans.sort()
    print(str(b)+":",*ans)
