S = input()
print("Yes" if sum([S[i:i+2]=="AC" for i in range(len(S))]) else "No")