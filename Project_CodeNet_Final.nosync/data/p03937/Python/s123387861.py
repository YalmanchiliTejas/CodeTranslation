h,w = map(int, input().split())
al = [input() for _ in range(h)]

for hi in range(h-1):
    for wi in range(w-1):
        if al[hi][wi]==al[hi+1][wi]==al[hi][wi+1]=="#":
            print("Impossible")
            exit()
        if al[hi+1][wi]==al[hi+1][wi+1]==al[hi][wi+1]=="#":
            print("Impossible")
            exit()
print("Possible")