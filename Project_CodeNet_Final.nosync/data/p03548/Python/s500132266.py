X,Y,Z = map(int,input().split())
#人がn人座る時必要な長さ(n+1)Z+nY<=X
# (Z+Y)n<=X-Z
# n<=(X-Z)/(Z+Y)
print(int((X-Z)/(Z+Y)))