n = int(input())
s = input()
k = int(input())
tar = s[k-1]
print ("".join([ it if it==tar else "*" for it in s ]))