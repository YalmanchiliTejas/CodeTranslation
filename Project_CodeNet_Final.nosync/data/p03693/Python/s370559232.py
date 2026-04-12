R,G,B = map(int, input().rstrip().split())

N = R*100 + G*10 + B
print("YES" if N%4 == 0 else "NO")