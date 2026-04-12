line = input()
num = [int(n) for n in line.split()][0]
predicted_value = "NO"
if num in [3, 5, 7]:
    predicted_value = "YES"
print(predicted_value)