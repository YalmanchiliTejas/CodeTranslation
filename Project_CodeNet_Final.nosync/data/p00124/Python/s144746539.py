class Team():

    def __init__(self, a, b):
        self.name = a
        self.score = b

flag = False
while True:
    N = int(input())
    if N == 0:
        break

    if flag:
        print("")
    else:
        flag = True

    teams = []
    for l in range(N):
        a,b,c,d = input().split()
        team = Team(a, int(b)*3 + int(d))
        teams.append(team)

    teams = sorted(teams, key=lambda u: u.score, reverse = True)
    for l in range(len(teams)):
        print(teams[l].name,end="")
        print(",",end="")
        print(teams[l].score)


