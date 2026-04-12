H,W=map(int,input().split())
a=[input() for i in range(H)]
for i in range(2):
    a=filter(lambda x:"#"in x,a)
    a=list(zip(*[list(_) for _ in a]))
print("\n".join(["".join(i) for i in a]))