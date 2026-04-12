line = input()
rgb = line.replace(" ", "")
rgb = int(rgb)
mul4 = rgb % 4== 0
if mul4:
    result = "YES"
else:
    result = "NO"
print(result)
