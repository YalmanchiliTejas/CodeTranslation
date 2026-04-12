idx = list(map(int, input().split()))

if((idx[0] * 100 + idx[1] * 10 + idx[2]) % 4):
    print("NO")
else:
    print("YES")
