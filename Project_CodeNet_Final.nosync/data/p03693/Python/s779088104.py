r,g,b = map(str, input().split())
print(["YES","NO","NO","NO"][int(r+g+b)%4])
