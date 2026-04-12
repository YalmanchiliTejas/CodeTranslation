while True:
    n=int(input())
    if n==0:break
    points=[]
    for i in range(n):
        points.append(int(input()))
    points.remove(max(points))
    points.remove(min(points))
    print(int(sum(points)/len(points)))