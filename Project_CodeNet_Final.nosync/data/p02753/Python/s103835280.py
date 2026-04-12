
import glob


# 問題ごとのディレクトリのトップからの相対パス
REL_PATH = 'ABC\\158\\A'

# テスト用ファイル置き場のトップ
TOP_PATH = 'C:\\AtCoder'

class Common:

    problem = []
    index = 0

    def __init__(self, rel_path):
        self.rel_path = rel_path

    def initialize(self, path):
        file = open(path)
        self.problem = file.readlines()
        self.index = 0
        return

    def input_data(self):
        try:
            IS_TEST
            self.index += 1
            return self.problem[self.index-1]

        except NameError:
            return input()

    def resolve(self):
        pass

    def exec_resolve(self):
        try:
            IS_TEST
            for path in glob.glob(TOP_PATH + '\\' + self.rel_path + '/*.txt'):
                print("Test: " + path)
                self.initialize(path)
                self.resolve()
                print("\n\n")
        except NameError:
            self.resolve()


class Solver(Common):

    def resolve(self):

        N = self.input_data()

        if "A" in N and "B" in N:
            print("Yes")
        else:
            print("No")


solver = Solver(REL_PATH)
solver.exec_resolve()
