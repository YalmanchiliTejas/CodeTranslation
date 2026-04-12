a,b,c,x,y=map(int, input().split())
answer=[]
for i in range(max(x,y)*2+1):
    answer.append((x-i//2)*a+(y-i//2)*b+i*c)
    if x-i//2<0:
        answer[i]=answer[i]-(x-i//2)*a
    if y-i//2<0:
        answer[i]=answer[i]-(y-i//2)*b
print(min(answer))