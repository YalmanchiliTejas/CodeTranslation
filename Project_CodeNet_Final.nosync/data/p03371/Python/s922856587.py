A,B,C,X,Y=map(int,input().split())
onedan=0
if A+B<=2*C:
    print(X*A+Y*B)
    exit()
onedan=min(X,Y)*2*C
if max(X,Y)==X:
    onedan+=(X-Y)*A
else:
    onedan+=(Y-X)*B
onedan=min(onedan,max(X,Y)*2*C)
print(onedan)