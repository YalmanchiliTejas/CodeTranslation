n = int(raw_input())
s = ["" for i in range(n)]

while True:
    a = raw_input().split()
    if a[0] == "quit":
        break

    i = int(a[1]) - 1
    if a[0] == "push":
        s[i] += a[2]

    elif a[0] == "pop":
        l = len(s[i]) - 1
        print s[i][l]
        s[i] = s[i][:l]

    elif a[0] == "move":
        j = int(a[2]) - 1 
        l = len(s[i]) - 1
        s[j] += s[i][l]
        s[i] = s[i][:l]