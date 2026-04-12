h,w=map(int,input().split())
c=sum(input().count("#") for _ in "*"*h)
print("Impossible Possible".split()[c==h+w-1])