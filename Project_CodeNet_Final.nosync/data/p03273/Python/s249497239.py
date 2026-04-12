H,W = map(int,input().split())
t = []
for i in range(H):
    x = list(input())
    if "#" in x:
        t.append(x)
for i in range(W):
    if all((t[j][i] == "." for j in range(len(t)))):
        for k in range(len(t)):
            t[k][i] = ""
for i in range(len(t)):
    print("".join(t[i]))