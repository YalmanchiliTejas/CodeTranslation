r,g,b = map(int,input().split())
shimohutaketa = 10 * g + b
if shimohutaketa % 4 ==0:
    print("YES")
else:
        print("NO")