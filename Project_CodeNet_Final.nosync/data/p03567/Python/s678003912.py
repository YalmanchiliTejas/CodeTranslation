data = input()
print("Yes" if "AC" in [data[i:i+2] for i in range(len(data)-1)] else "No")