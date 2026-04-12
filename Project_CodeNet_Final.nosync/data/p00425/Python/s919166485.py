def roll(die, d):
    if d == "E":
        return [die[3], die[1], die[0], die[5], die[4], die[2]]
    if d == "N":
        return [die[1], die[5], die[2], die[3], die[0], die[4]]
    if d == "S":
        return [die[4], die[0], die[2], die[3], die[5], die[1]]
    if d == "W":
        return [die[2], die[1], die[5], die[0], die[4], die[3]]
    if d == "L":
        return [die[0], die[3], die[1], die[4], die[2], die[5]]
    if d == "R":
        return [die[0], die[2], die[4], die[1], die[3], die[5]]

while True:
    die = [1, 2, 3, 4, 5, 6]
    ans = 1
    n = int(input())
    if n == 0:
        break
    for _ in range(n):
        die = roll(die, input()[0])
        ans += die[0]
    print(ans)