h, w = map(int, input().split())
a = [input() for _i in range(h)]
p = 0
for i in range(h):
    x = [j for j in range(w) if a[i][j]=="#"]
    for j in range(len(x)-1):
        if x[j]+1==x[j+1]:
            continue
        else:
            import sys
            print("Impossible")
            sys.exit()
    if p==x[0]:
        p = x[-1]
    else:
        import sys
        print("Impossible")
        sys.exit()
print("Possible")