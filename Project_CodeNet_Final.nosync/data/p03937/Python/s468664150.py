h, w = map(int,input().split())
A = [input() for i in range(h)]

# print(A)

def a():
    c = -1
    for i in range(len(A)):
        c += A[i].count("#")
    
    s = [0, 0]
    while s != [h-1, w-1]:
        # print(s)
        if s[1]+1 < w and A[s[0]][s[1]+1] == "#":
            s[1] += 1
            c -= 1
        elif s[0]+1 < h and A[s[0]+1][s[1]] == "#":
            s[0] += 1
            c -= 1
        else:
            return "Impossible"
    if c == 0:
        return "Possible"
    else:
        return "Impossible"

print(a())