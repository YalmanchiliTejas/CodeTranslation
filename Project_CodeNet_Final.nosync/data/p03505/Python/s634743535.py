k,a,b=map(int,input().split())
print(1 if k<=a else 1+(k-b-1)//(a-b)*2 if a>b else -1)