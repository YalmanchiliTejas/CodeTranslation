k, a, b = map(int, input().split())
if a <= b:
    print(1 if k <= a else -1)
else:
    print(min((k+a-b-1)//(a-b)*2, (k-a+a-b-1)//(a-b)*2+1))