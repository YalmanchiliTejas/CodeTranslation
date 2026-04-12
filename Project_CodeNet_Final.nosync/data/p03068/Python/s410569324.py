n = int(input())
s = input()
k = int(input())
moji = s[k-1]
print(''.join(['*' if item != moji else item for item in s]))
