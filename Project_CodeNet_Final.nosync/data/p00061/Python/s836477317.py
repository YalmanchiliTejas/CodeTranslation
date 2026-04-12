
import sys
import itertools


class Team:
    def __init__(self, number, score):
        self.number = number
        self.score = score


class RankChecker:
    def __init__(self):
        self.teams = []

    def add(self, team):
        self.teams.append(team)

    def aggregate(self):
        self.teams.sort(key=lambda t: t.score, reverse=True)
        r = 0
        for k, g in itertools.groupby(self.teams, key=lambda t: t.score):
            r += 1
            for t in g:
                t.rank = r

    def check_rank(self, team_number):
        team = filter(lambda t: t.number == team_number, self.teams)[0]
        return team.rank



rc = RankChecker()
for line in sys.stdin:
    num, score = map(int, line.strip().split(','))
    if (num, score) == (0, 0):
        break
    rc.add(Team(num, score))
rc.aggregate()
for line in sys.stdin:
    num = int(line)
    print rc.check_rank(num)