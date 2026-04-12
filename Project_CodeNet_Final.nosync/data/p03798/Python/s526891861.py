N = int(raw_input())
s = raw_input()

D = ["SS", "SW", "WS", "WW"]
A = "SW"

s += s[0]
for d in D:
    a = d
    for i in range(1, N+1):
        k = 0
        if a[i] == "W":
            k += 1
        if s[i] == "x":
            k += 1
        if a[i-1] == "W":
            k += 1
        a += A[k % 2]
    if a[:2] == a[-2:]:
        print a[:-2]
        exit()
print -1
