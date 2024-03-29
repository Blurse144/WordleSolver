// Wordle.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

//This is all of the words that can be solutions for Wordle, pulled straight from the origional source code. NYT's acquisition may have changed this, but there is nothing to be done without making the program much more complex. Coming soon ;).
vector<string> PossibleSolutions{ "sissy", "humph", "awake", "blush", "focal", "evade", "naval", "serve", "heath", "dwarf", "model", "karma", "stink", "grade", "quiet", "bench", "abate", "feign", "major", "death", "fresh", "crust", "stool", "colon", "abase", "marry", "react", "batty", "pride", "floss", "helix", "croak", "staff", "paper", "unfed", "whelp", "trawl", "outdo", "adobe", "crazy", "sower", "repay", "digit", "crate", "cluck", "spike", "mimic", "pound", "maxim", "linen", "unmet", "flesh", "booby", "forth", "first", "stand", "belly", "ivory", "seedy", "print", "yearn", "drain", "bribe", "stout", "panel", "crass", "flume", "offal", "agree", "error", "swirl", "argue", "bleed", "delta", "flick", "totem", "wooer", "front", "shrub", "parry", "biome", "lapel", "start", "greet", "goner", "golem", "lusty", "loopy", "round", "audit", "lying", "gamma", "labor", "islet", "civic", "forge", "corny", "moult", "basic", "salad", "agate", "spicy", "spray", "essay", "fjord", "spend", "kebab", "guild", "aback", "motor", "alone", "hatch", "hyper", "thumb", "dowry", "ought", "belch", "dutch", "pilot", "tweed", "comet", "jaunt", "enema", "steed", "abyss", "growl", "fling", "dozen", "boozy", "erode", "world", "gouge", "click", "briar", "great", "altar", "pulpy", "blurt", "coast", "duchy", "groin", "fixer", "group", "rogue", "badly", "smart", "pithy", "gaudy", "chill", "heron", "vodka", "finer", "surer", "radio", "rouge", "perch", "retch", "wrote", "clock", "tilde", "store", "prove", "bring", "solve", "cheat", "grime", "exult", "usher", "epoch", "triad", "break", "rhino", "viral", "conic", "masse", "sonic", "vital", "trace", "using", "peach", "champ", "baton", "brake", "pluck", "craze", "gripe", "weary", "picky", "acute", "ferry", "aside", "tapir", "troll", "unify", "rebus", "boost", "truss", "siege", "tiger", "banal", "slump", "crank", "gorge", "query", "drink", "favor", "abbey", "tangy", "panic", "solar", "shire", "proxy", "point", "robot", "prick", "wince", "crimp", "knoll", "sugar", "whack", "mount", "perky", "could", "wrung", "light", "those", "moist", "shard", "pleat", "aloft", "skill", "elder", "frame", "humor", "pause", "ulcer", "ultra", "robin", "cynic", "aroma", "caulk", "shake", "dodge", "swill", "tacit", "other", "thorn", "trove", "bloke", "vivid", "spill", "chant", "choke", "rupee", "nasty", "mourn", "ahead", "brine", "cloth", "hoard", "sweet", "month", "lapse", "watch", "today", "focus", "smelt", "tease", "cater", "movie", "saute", "allow", "renew", "their", "slosh", "purge", "chest", "depot", "epoxy", "nymph", "found", "shall", "harry", "stove", "lowly", "snout", "trope", "fewer", "shawl", "natal", "comma", "foray", "scare", "stair", "black", "squad", "royal", "chunk", "mince", "slave", "shame", "cheek", "ample", "flair", "foyer", "cargo", "oxide", "plant", "olive", "inert", "askew", "heist", "shown", "zesty", "hasty", "trash", "fella", "larva", "forgo", "story", "hairy", "train", "homer", "badge", "midst", "canny", "fetus", "butch", "farce", "slung", "tipsy", "metal", "yield", "delve", "being", "scour", "glass", "gamer", "scrap", "money", "hinge", "album", "vouch", "asset", "tiara", "crept", "bayou", "atoll", "manor", "creak", "showy", "phase", "froth", "depth", "gloom", "flood", "trait", "girth", "piety", "payer", "goose", "float", "donor", "atone", "primo", "apron", "blown", "cacao", "loser", "input", "gloat", "awful", "brink", "smite", "beady", "rusty", "retro", "droll", "gawky", "hutch", "pinto", "gaily", "egret", "lilac", "sever", "field", "fluff", "hydro", "flack", "agape", "voice", "stead", "stalk", "berth", "madam", "night", "bland", "liver", "wedge", "augur", "roomy", "wacky", "flock", "angry", "bobby", "trite", "aphid", "tryst", "midge", "power", "elope", "cinch", "motto", "stomp", "upset", "bluff", "cramp", "quart", "coyly", "youth", "rhyme", "buggy", "alien", "smear", "unfit", "patty", "cling", "glean", "label", "hunky", "khaki", "poker", "gruel", "twice", "twang", "shrug", "treat", "unlit", "waste", "merit", "woven", "octal", "needy", "clown", "widow", "irony", "ruder", "gauze", "chief", "onset", "prize", "fungi", "charm", "gully", "inter", "whoop", "taunt", "leery", "class", "theme", "lofty", "tibia", "booze", "alpha", "thyme", "eclat", "doubt", "parer", "chute", "stick", "trice", "alike", "sooth", "recap", "saint", "liege", "glory", "grate", "admit", "brisk", "soggy", "usurp", "scald", "scorn", "leave", "twine", "sting", "bough", "marsh", "sloth", "dandy", "vigor", "howdy", "enjoy", "valid", "ionic", "equal", "unset", "floor", "catch", "spade", "stein", "exist", "quirk", "denim", "grove", "spiel", "mummy", "fault", "foggy", "flout", "carry", "sneak", "libel", "waltz", "aptly", "piney", "inept", "aloud", "photo", "dream", "stale", "vomit", "ombre", "fanny", "unite", "snarl", "baker", "there", "glyph", "pooch", "hippy", "spell", "folly", "louse", "gulch", "vault", "godly", "threw", "fleet", "grave", "inane", "shock", "crave", "spite", "valve", "skimp", "claim", "rainy", "musty", "pique", "daddy", "quasi", "arise", "aging", "valet", "opium", "avert", "stuck", "recut", "mulch", "genre", "plume", "rifle", "count", "incur", "total", "wrest", "mocha", "deter", "study", "lover", "safer", "rivet", "funny", "smoke", "mound", "undue", "sedan", "pagan", "swine", "guile", "gusty", "equip", "tough", "canoe", "chaos", "covet", "human", "udder", "lunch", "blast", "stray", "manga", "melee", "lefty", "quick", "paste", "given", "octet", "risen", "groan", "leaky", "grind", "carve", "loose", "sadly", "spilt", "apple", "slack", "honey", "final", "sheen", "eerie", "minty", "slick", "derby", "wharf", "spelt", "coach", "erupt", "singe", "price", "spawn", "fairy", "jiffy", "filmy", "stack", "chose", "sleep", "ardor", "nanny", "niece", "woozy", "handy", "grace", "ditto", "stank", "cream", "usual", "diode", "valor", "angle", "ninja", "muddy", "chase", "reply", "prone", "spoil", "heart", "shade", "diner", "arson", "onion", "sleet", "dowel", "couch", "palsy", "bowel", "smile", "evoke", "creek", "lance", "eagle", "idiot", "siren", "built", "embed", "award", "dross", "annul", "goody", "frown", "patio", "laden", "humid", "elite", "lymph", "edify", "might", "reset", "visit", "gusto", "purse", "vapor", "crock", "write", "sunny", "loath", "chaff", "slide", "queer", "venom", "stamp", "sorry", "still", "acorn", "aping", "pushy", "tamer", "hater", "mania", "awoke", "brawn", "swift", "exile", "birch", "lucky", "freer", "risky", "ghost", "plier", "lunar", "winch", "snare", "nurse", "house", "borax", "nicer", "lurch", "exalt", "about", "savvy", "toxin", "tunic", "pried", "inlay", "chump", "lanky", "cress", "eater", "elude", "cycle", "kitty", "boule", "moron", "tenet", "place", "lobby", "plush", "vigil", "index", "blink", "clung", "qualm", "croup", "clink", "juicy", "stage", "decay", "nerve", "flier", "shaft", "crook", "clean", "china", "ridge", "vowel", "gnome", "snuck", "icing", "spiny", "rigor", "snail", "flown", "rabid", "prose", "thank", "poppy", "budge", "fiber", "moldy", "dowdy", "kneel", "track", "caddy", "quell", "dumpy", "paler", "swore", "rebar", "scuba", "splat", "flyer", "horny", "mason", "doing", "ozone", "amply", "molar", "ovary", "beset", "queue", "cliff", "magic", "truce", "sport", "fritz", "edict", "twirl", "verse", "llama", "eaten", "range", "whisk", "hovel", "rehab", "macaw", "sigma", "spout", "verve", "sushi", "dying", "fetid", "brain", "buddy", "thump", "scion", "candy", "chord", "basin", "march", "crowd", "arbor", "gayly", "musky", "stain", "dally", "bless", "bravo", "stung", "title", "ruler", "kiosk", "blond", "ennui", "layer", "fluid", "tatty", "score", "cutie", "zebra", "barge", "matey", "bluer", "aider", "shook", "river", "privy", "betel", "frisk", "bongo", "begun", "azure", "weave", "genie", "sound", "glove", "braid", "scope", "wryly", "rover", "assay", "ocean", "bloom", "irate", "later", "woken", "silky", "wreck", "dwelt", "slate", "smack", "solid", "amaze", "hazel", "wrist", "jolly", "globe", "flint", "rouse", "civil", "vista", "relax", "cover", "alive", "beech", "jetty", "bliss", "vocal", "often", "dolly", "eight", "joker", "since", "event", "ensue", "shunt", "diver", "poser", "worst", "sweep", "alley", "creed", "anime", "leafy", "bosom", "dunce", "stare", "pudgy", "waive", "choir", "stood", "spoke", "outgo", "delay", "bilge", "ideal", "clasp", "seize", "hotly", "laugh", "sieve", "block", "meant", "grape", "noose", "hardy", "shied", "drawl", "daisy", "putty", "strut", "burnt", "tulip", "crick", "idyll", "vixen", "furor", "geeky", "cough", "naive", "shoal", "stork", "bathe", "aunty", "check", "prime", "brass", "outer", "furry", "razor", "elect", "evict", "imply", "demur", "quota", "haven", "cavil", "swear", "crump", "dough", "gavel", "wagon", "salon", "nudge", "harem", "pitch", "sworn", "pupil", "excel", "stony", "cabin", "unzip", "queen", "trout", "polyp", "earth", "storm", "until", "taper", "enter", "child", "adopt", "minor", "fatty", "husky", "brave", "filet", "slime", "glint", "tread", "steal", "regal", "guest", "every", "murky", "share", "spore", "hoist", "buxom", "inner", "otter", "dimly", "level", "sumac", "donut", "stilt", "arena", "sheet", "scrub", "fancy", "slimy", "pearl", "silly", "porch", "dingo", "sepia", "amble", "shady", "bread", "friar", "reign", "dairy", "quill", "cross", "brood", "tuber", "shear", "posit", "blank", "villa", "shank", "piggy", "freak", "which", "among", "fecal", "shell", "would", "algae", "large", "rabbi", "agony", "amuse", "bushy", "copse", "swoon", "knife", "pouch", "ascot", "plane", "crown", "urban", "snide", "relay", "abide", "viola", "rajah", "straw", "dilly", "crash", "amass", "third", "trick", "tutor", "woody", "blurb", "grief", "disco", "where", "sassy", "beach", "sauna", "comic", "clued", "creep", "caste", "graze", "snuff", "frock", "gonad", "drunk", "prong", "lurid", "steel", "halve", "buyer", "vinyl", "utile", "smell", "adage", "worry", "tasty", "local", "trade", "finch", "ashen", "modal", "gaunt", "clove", "enact", "adorn", "roast", "speck", "sheik", "missy", "grunt", "snoop", "party", "touch", "mafia", "emcee", "array", "south", "vapid", "jelly", "skulk", "angst", "tubal", "lower", "crest", "sweat", "cyber", "adore", "tardy", "swami", "notch", "groom", "roach", "hitch", "young", "align", "ready", "frond", "strap", "puree", "realm", "venue", "swarm", "offer", "seven", "dryer", "diary", "dryly", "drank", "acrid", "heady", "theta", "junto", "pixie", "quoth", "bonus", "shalt", "penne", "amend", "datum", "build", "piano", "shelf", "lodge", "suing", "rearm", "coral", "ramen", "worth", "psalm", "infer", "overt", "mayor", "ovoid", "glide", "usage", "poise", "randy", "chuck", "prank", "fishy", "tooth", "ether", "drove", "idler", "swath", "stint", "while", "begat", "apply", "slang", "tarot", "radar", "credo", "aware", "canon", "shift", "timer", "bylaw", "serum", "three", "steak", "iliac", "shirk", "blunt", "puppy", "penal", "joist", "bunny", "shape", "beget", "wheel", "adept", "stunt", "stole", "topaz", "chore", "fluke", "afoot", "bloat", "bully", "dense", "caper", "sneer", "boxer", "jumbo", "lunge", "space", "avail", "short", "slurp", "loyal", "flirt", "pizza", "conch", "tempo", "droop", "plate", "bible", "plunk", "afoul", "savoy", "steep", "agile", "stake", "dwell", "knave", "beard", "arose", "motif", "smash", "broil", "glare", "shove", "baggy", "mammy", "swamp", "along", "rugby", "wager", "quack", "squat", "snaky", "debit", "mange", "skate", "ninth", "joust", "tramp", "spurn", "medal", "micro", "rebel", "flank", "learn", "nadir", "maple", "comfy", "remit", "gruff", "ester", "least", "mogul", "fetch", "cause", "oaken", "aglow", "meaty", "gaffe", "shyly", "racer", "prowl", "thief", "stern", "poesy", "rocky", "tweet", "waist", "spire", "grope", "havoc", "patsy", "truly", "forty", "deity", "uncle", "swish", "giver", "preen", "bevel", "lemur", "draft", "slope", "annoy", "lingo", "bleak", "ditty", "curly", "cedar", "dirge", "grown", "horde", "drool", "shuck", "crypt", "cumin", "stock", "gravy", "locus", "wider", "breed", "quite", "chafe", "cache", "blimp", "deign", "fiend", "logic", "cheap", "elide", "rigid", "false", "renal", "pence", "rowdy", "shoot", "blaze", "envoy", "posse", "brief", "never", "abort", "mouse", "mucky", "sulky", "fiery", "media", "trunk", "yeast", "clear", "skunk", "scalp", "bitty", "cider", "koala", "duvet", "segue", "creme", "super", "grill", "after", "owner", "ember", "reach", "nobly", "empty", "speed", "gipsy", "recur", "smock", "dread", "merge", "burst", "kappa", "amity", "shaky", "hover", "carol", "snort", "synod", "faint", "haunt", "flour", "chair", "detox", "shrew", "tense", "plied", "quark", "burly", "novel", "waxen", "stoic", "jerky", "blitz", "beefy", "lyric", "hussy", "towel", "quilt", "below", "bingo", "wispy", "brash", "scone", "toast", "easel", "saucy", "value", "spice", "honor", "route", "sharp", "bawdy", "radii", "skull", "phony", "issue", "lager", "swell", "urine", "gassy", "trial", "flora", "upper", "latch", "wight", "brick", "retry", "holly", "decal", "grass", "shack", "dogma", "mover", "defer", "sober", "optic", "crier", "vying", "nomad", "flute", "hippo", "shark", "drier", "obese", "bugle", "tawny", "chalk", "feast", "ruddy", "pedal", "scarf", "cruel", "bleat", "tidal", "slush", "semen", "windy", "dusty", "sally", "igloo", "nerdy", "jewel", "shone", "whale", "hymen", "abuse", "fugue", "elbow", "crumb", "pansy", "welsh", "syrup", "terse", "suave", "gamut", "swung", "drake", "freed", "afire", "shirt", "grout", "oddly", "tithe", "plaid", "dummy", "broom", "blind", "torch", "enemy", "again", "tying", "pesky", "alter", "gazer", "noble", "ethos", "bride", "extol", "decor", "hobby", "beast", "idiom", "utter", "these", "sixth", "alarm", "erase", "elegy", "spunk", "piper", "scaly", "scold", "hefty", "chick", "sooty", "canal", "whiny", "slash", "quake", "joint", "swept", "prude", "heavy", "wield", "femme", "lasso", "maize", "shale", "screw", "spree", "smoky", "whiff", "scent", "glade", "spent", "prism", "stoke", "riper", "orbit", "cocoa", "guilt", "humus", "shush", "table", "smirk", "wrong", "noisy", "alert", "shiny", "elate", "resin", "whole", "hunch", "pixel", "polar", "hotel", "sword", "cleat", "mango", "rumba", "puffy", "filly", "billy", "leash", "clout", "dance", "ovate", "facet", "chili", "paint", "liner", "curio", "salty", "audio", "snake", "fable", "cloak", "navel", "spurt", "pesto", "balmy", "flash", "unwed", "early", "churn", "weedy", "stump", "lease", "witty", "wimpy", "spoof", "saner", "blend", "salsa", "thick", "warty", "manic", "blare", "squib", "spoon", "probe", "crepe", "knack", "force", "debut", "order", "haste", "teeth", "agent", "widen", "icily", "slice", "ingot", "clash", "juror", "blood", "abode", "throw", "unity", "pivot", "slept", "troop", "spare", "sewer", "parse", "morph", "cacti", "tacky", "spool", "demon", "moody", "annex", "begin", "fuzzy", "patch", "water", "lumpy", "admin", "omega", "limit", "tabby", "macho", "aisle", "skiff", "basis", "plank", "verge", "botch", "crawl", "lousy", "slain", "cubic", "raise", "wrack", "guide", "foist", "cameo", "under", "actor", "revue", "fraud", "harpy", "scoop", "climb", "refer", "olden", "clerk", "debar", "tally", "ethic", "cairn", "tulle", "ghoul", "hilly", "crude", "apart", "scale", "older", "plain", "sperm", "briny", "abbot", "rerun", "quest", "crisp", "bound", "befit", "drawn", "suite", "itchy", "cheer", "bagel", "guess", "broad", "axiom", "chard", "caput", "leant", "harsh", "curse", "proud", "swing", "opine", "taste", "lupus", "gumbo", "miner", "green", "chasm", "lipid", "topic", "armor", "brush", "crane", "mural", "abled", "habit", "bossy", "maker", "dusky", "dizzy", "lithe", "brook", "jazzy", "fifty", "sense", "giant", "surly", "legal", "fatal", "flunk", "began", "prune", "small", "slant", "scoff", "torus", "ninny", "covey", "viper", "taken", "moral", "vogue", "owing", "token", "entry", "booth", "voter", "chide", "elfin", "ebony", "neigh", "minim", "melon", "kneed", "decoy", "voila", "ankle", "arrow", "mushy", "tribe", "cease", "eager", "birth", "graph", "odder", "terra", "weird", "tried", "clack", "color", "rough", "weigh", "uncut", "ladle", "strip", "craft", "minus", "dicey", "titan", "lucid", "vicar", "dress", "ditch", "gypsy", "pasta", "taffy", "flame", "swoop", "aloof", "sight", "broke", "teary", "chart", "sixty", "wordy", "sheer", "leper", "nosey", "bulge", "savor", "clamp", "funky", "foamy", "toxic", "brand", "plumb", "dingy", "butte", "drill", "tripe", "bicep", "tenor", "krill", "worse", "drama", "hyena", "think", "ratio", "cobra", "basil", "scrum", "bused", "phone", "court", "camel", "proof", "heard", "angel", "petal", "pouty", "throb", "maybe", "fetal", "sprig", "spine", "shout", "cadet", "macro", "dodgy", "satyr", "rarer", "binge", "trend", "nutty", "leapt", "amiss", "split", "myrrh", "width", "sonar", "tower", "baron", "fever", "waver", "spark", "belie", "sloop", "expel", "smote", "baler", "above", "north", "wafer", "scant", "frill", "awash", "snack", "scowl", "frail", "drift", "limbo", "fence", "motel", "ounce", "wreak", "revel", "talon", "prior", "knelt", "cello", "flake", "debug", "anode", "crime", "salve", "scout", "imbue", "pinky", "stave", "vague", "chock", "fight", "video", "stone", "teach", "cleft", "frost", "prawn", "booty", "twist", "apnea", "stiff", "plaza", "ledge", "tweak", "board", "grant", "medic", "bacon", "cable", "brawl", "slunk", "raspy", "forum", "drone", "women", "mucus", "boast", "toddy", "coven", "tumor", "truer", "wrath", "stall", "steam", "axial", "purer", "daily", "trail", "niche", "mealy", "juice", "nylon", "plump", "merry", "flail", "papal", "wheat", "berry", "cower", "erect", "brute", "leggy", "snipe", "sinew", "skier", "penny", "jumpy", "rally", "umbra", "scary", "modem", "gross", "avian", "greed", "satin", "tonic", "parka", "sniff", "livid", "stark", "trump", "giddy", "reuse", "taboo", "avoid", "quote", "devil", "liken", "gloss", "gayer", "beret", "noise", "gland", "dealt", "sling", "rumor", "opera", "thigh", "tonga", "flare", "wound", "white", "bulky", "etude", "horse", "circa", "paddy", "inbox", "fizzy", "grain", "exert", "surge", "gleam", "belle", "salvo", "crush", "fruit", "sappy", "taker", "tract", "ovine", "spiky", "frank", "reedy", "filth", "spasm", "heave", "mambo", "right", "clank", "trust", "lumen", "borne", "spook", "sauce", "amber", "lathe", "carat", "corer", "dirty", "slyly", "affix", "alloy", "taint", "sheep", "kinky", "wooly", "mauve", "flung", "yacht", "fried", "quail", "brunt", "grimy", "curvy", "cagey", "rinse", "deuce", "state", "grasp", "milky", "bison", "graft", "sandy", "baste", "flask", "hedge", "girly", "swash", "boney", "coupe", "endow", "abhor", "welch", "blade", "tight", "geese", "miser", "mirth", "cloud", "cabal", "leech", "close", "tenth", "pecan", "droit", "grail", "clone", "guise", "ralph", "tango", "biddy", "smith", "mower", "payee", "serif", "drape", "fifth", "spank", "glaze", "allot", "truck", "kayak", "virus", "testy", "tepee", "fully", "zonal", "metro", "curry", "grand", "banjo", "axion", "bezel", "occur", "chain", "nasal", "gooey", "filer", "brace", "allay", "pubic", "raven", "plead", "gnash", "flaky", "munch", "dully", "eking", "thing", "slink", "hurry", "theft", "shorn", "pygmy", "ranch", "wring", "lemon", "shore", "mamma", "froze", "newer", "style", "moose", "antic", "drown", "vegan", "chess", "guppy", "union", "lever", "lorry", "image", "cabby", "druid", "exact", "truth", "dopey", "spear", "cried", "chime", "crony", "stunk", "timid", "batch", "gauge", "rotor", "crack", "curve", "latte", "witch", "bunch", "repel", "anvil", "soapy", "meter", "broth", "madly", "dried", "scene", "known", "magma", "roost", "woman", "thong", "punch", "pasty", "downy", "knead", "whirl", "rapid", "clang", "anger", "drive", "goofy", "email", "music", "stuff", "bleep", "rider", "mecca", "folio", "setup", "verso", "quash", "fauna", "gummy", "happy", "newly", "fussy", "relic", "guava", "ratty", "fudge", "femur", "chirp", "forte", "alibi", "whine", "petty", "golly", "plait", "fleck", "felon", "gourd", "brown", "thrum", "ficus", "stash", "decry", "wiser", "junta", "visor", "daunt", "scree", "impel", "await", "press", "whose", "turbo", "stoop", "speak", "mangy", "eying", "inlet", "crone", "pulse", "mossy", "staid", "hence", "pinch", "teddy", "sully", "snore", "ripen", "snowy", "attic", "going", "leach", "mouth", "hound", "clump", "tonal", "bigot", "peril", "piece", "blame", "haute", "spied", "undid", "intro", "basal", "shine", "gecko", "rodeo", "guard", "steer", "loamy", "scamp", "scram", "manly", "hello", "vaunt", "organ", "feral", "knock", "extra", "condo", "adapt", "willy", "polka", "rayon", "skirt", "faith", "torso", "match", "mercy", "tepid", "sleek", "riser", "twixt", "peace", "flush", "catty", "login", "eject", "roger", "rival", "untie", "refit", "aorta", "adult", "judge", "rower", "artsy", "rural", "shave" };
//The previous vector, except every word is split into its letters. May be unnecessary and may be removed in next version.
vector<char> PossibleChars{ 's', 'i', 's', 's', 'y', 'h', 'u', 'm', 'p', 'h', 'a', 'w', 'a', 'k', 'e', 'b', 'l', 'u', 's', 'h', 'f', 'o', 'c', 'a', 'l', 'e', 'v', 'a', 'd', 'e', 'n', 'a', 'v', 'a', 'l', 's', 'e', 'r', 'v', 'e', 'h', 'e', 'a', 't', 'h', 'd', 'w', 'a', 'r', 'f', 'm', 'o', 'd', 'e', 'l', 'k', 'a', 'r', 'm', 'a', 's', 't', 'i', 'n', 'k', 'g', 'r', 'a', 'd', 'e', 'q', 'u', 'i', 'e', 't', 'b', 'e', 'n', 'c', 'h', 'a', 'b', 'a', 't', 'e', 'f', 'e', 'i', 'g', 'n', 'm', 'a', 'j', 'o', 'r', 'd', 'e', 'a', 't', 'h', 'f', 'r', 'e', 's', 'h', 'c', 'r', 'u', 's', 't', 's', 't', 'o', 'o', 'l', 'c', 'o', 'l', 'o', 'n', 'a', 'b', 'a', 's', 'e', 'm', 'a', 'r', 'r', 'y', 'r', 'e', 'a', 'c', 't', 'b', 'a', 't', 't', 'y', 'p', 'r', 'i', 'd', 'e', 'f', 'l', 'o', 's', 's', 'h', 'e', 'l', 'i', 'x', 'c', 'r', 'o', 'a', 'k', 's', 't', 'a', 'f', 'f', 'p', 'a', 'p', 'e', 'r', 'u', 'n', 'f', 'e', 'd', 'w', 'h', 'e', 'l', 'p', 't', 'r', 'a', 'w', 'l', 'o', 'u', 't', 'd', 'o', 'a', 'd', 'o', 'b', 'e', 'c', 'r', 'a', 'z', 'y', 's', 'o', 'w', 'e', 'r', 'r', 'e', 'p', 'a', 'y', 'd', 'i', 'g', 'i', 't', 'c', 'r', 'a', 't', 'e', 'c', 'l', 'u', 'c', 'k', 's', 'p', 'i', 'k', 'e', 'm', 'i', 'm', 'i', 'c', 'p', 'o', 'u', 'n', 'd', 'm', 'a', 'x', 'i', 'm', 'l', 'i', 'n', 'e', 'n', 'u', 'n', 'm', 'e', 't', 'f', 'l', 'e', 's', 'h', 'b', 'o', 'o', 'b', 'y', 'f', 'o', 'r', 't', 'h', 'f', 'i', 'r', 's', 't', 's', 't', 'a', 'n', 'd', 'b', 'e', 'l', 'l', 'y', 'i', 'v', 'o', 'r', 'y', 's', 'e', 'e', 'd', 'y', 'p', 'r', 'i', 'n', 't', 'y', 'e', 'a', 'r', 'n', 'd', 'r', 'a', 'i', 'n', 'b', 'r', 'i', 'b', 'e', 's', 't', 'o', 'u', 't', 'p', 'a', 'n', 'e', 'l', 'c', 'r', 'a', 's', 's', 'f', 'l', 'u', 'm', 'e', 'o', 'f', 'f', 'a', 'l', 'a', 'g', 'r', 'e', 'e', 'e', 'r', 'r', 'o', 'r', 's', 'w', 'i', 'r', 'l', 'a', 'r', 'g', 'u', 'e', 'b', 'l', 'e', 'e', 'd', 'd', 'e', 'l', 't', 'a', 'f', 'l', 'i', 'c', 'k', 't', 'o', 't', 'e', 'm', 'w', 'o', 'o', 'e', 'r', 'f', 'r', 'o', 'n', 't', 's', 'h', 'r', 'u', 'b', 'p', 'a', 'r', 'r', 'y', 'b', 'i', 'o', 'm', 'e', 'l', 'a', 'p', 'e', 'l', 's', 't', 'a', 'r', 't', 'g', 'r', 'e', 'e', 't', 'g', 'o', 'n', 'e', 'r', 'g', 'o', 'l', 'e', 'm', 'l', 'u', 's', 't', 'y', 'l', 'o', 'o', 'p', 'y', 'r', 'o', 'u', 'n', 'd', 'a', 'u', 'd', 'i', 't', 'l', 'y', 'i', 'n', 'g', 'g', 'a', 'm', 'm', 'a', 'l', 'a', 'b', 'o', 'r', 'i', 's', 'l', 'e', 't', 'c', 'i', 'v', 'i', 'c', 'f', 'o', 'r', 'g', 'e', 'c', 'o', 'r', 'n', 'y', 'm', 'o', 'u', 'l', 't', 'b', 'a', 's', 'i', 'c', 's', 'a', 'l', 'a', 'd', 'a', 'g', 'a', 't', 'e', 's', 'p', 'i', 'c', 'y', 's', 'p', 'r', 'a', 'y', 'e', 's', 's', 'a', 'y', 'f', 'j', 'o', 'r', 'd', 's', 'p', 'e', 'n', 'd', 'k', 'e', 'b', 'a', 'b', 'g', 'u', 'i', 'l', 'd', 'a', 'b', 'a', 'c', 'k', 'm', 'o', 't', 'o', 'r', 'a', 'l', 'o', 'n', 'e', 'h', 'a', 't', 'c', 'h', 'h', 'y', 'p', 'e', 'r', 't', 'h', 'u', 'm', 'b', 'd', 'o', 'w', 'r', 'y', 'o', 'u', 'g', 'h', 't', 'b', 'e', 'l', 'c', 'h', 'd', 'u', 't', 'c', 'h', 'p', 'i', 'l', 'o', 't', 't', 'w', 'e', 'e', 'd', 'c', 'o', 'm', 'e', 't', 'j', 'a', 'u', 'n', 't', 'e', 'n', 'e', 'm', 'a', 's', 't', 'e', 'e', 'd', 'a', 'b', 'y', 's', 's', 'g', 'r', 'o', 'w', 'l', 'f', 'l', 'i', 'n', 'g', 'd', 'o', 'z', 'e', 'n', 'b', 'o', 'o', 'z', 'y', 'e', 'r', 'o', 'd', 'e', 'w', 'o', 'r', 'l', 'd', 'g', 'o', 'u', 'g', 'e', 'c', 'l', 'i', 'c', 'k', 'b', 'r', 'i', 'a', 'r', 'g', 'r', 'e', 'a', 't', 'a', 'l', 't', 'a', 'r', 'p', 'u', 'l', 'p', 'y', 'b', 'l', 'u', 'r', 't', 'c', 'o', 'a', 's', 't', 'd', 'u', 'c', 'h', 'y', 'g', 'r', 'o', 'i', 'n', 'f', 'i', 'x', 'e', 'r', 'g', 'r', 'o', 'u', 'p', 'r', 'o', 'g', 'u', 'e', 'b', 'a', 'd', 'l', 'y', 's', 'm', 'a', 'r', 't', 'p', 'i', 't', 'h', 'y', 'g', 'a', 'u', 'd', 'y', 'c', 'h', 'i', 'l', 'l', 'h', 'e', 'r', 'o', 'n', 'v', 'o', 'd', 'k', 'a', 'f', 'i', 'n', 'e', 'r', 's', 'u', 'r', 'e', 'r', 'r', 'a', 'd', 'i', 'o', 'r', 'o', 'u', 'g', 'e', 'p', 'e', 'r', 'c', 'h', 'r', 'e', 't', 'c', 'h', 'w', 'r', 'o', 't', 'e', 'c', 'l', 'o', 'c', 'k', 't', 'i', 'l', 'd', 'e', 's', 't', 'o', 'r', 'e', 'p', 'r', 'o', 'v', 'e', 'b', 'r', 'i', 'n', 'g', 's', 'o', 'l', 'v', 'e', 'c', 'h', 'e', 'a', 't', 'g', 'r', 'i', 'm', 'e', 'e', 'x', 'u', 'l', 't', 'u', 's', 'h', 'e', 'r', 'e', 'p', 'o', 'c', 'h', 't', 'r', 'i', 'a', 'd', 'b', 'r', 'e', 'a', 'k', 'r', 'h', 'i', 'n', 'o', 'v', 'i', 'r', 'a', 'l', 'c', 'o', 'n', 'i', 'c', 'm', 'a', 's', 's', 'e', 's', 'o', 'n', 'i', 'c', 'v', 'i', 't', 'a', 'l', 't', 'r', 'a', 'c', 'e', 'u', 's', 'i', 'n', 'g', 'p', 'e', 'a', 'c', 'h', 'c', 'h', 'a', 'm', 'p', 'b', 'a', 't', 'o', 'n', 'b', 'r', 'a', 'k', 'e', 'p', 'l', 'u', 'c', 'k', 'c', 'r', 'a', 'z', 'e', 'g', 'r', 'i', 'p', 'e', 'w', 'e', 'a', 'r', 'y', 'p', 'i', 'c', 'k', 'y', 'a', 'c', 'u', 't', 'e', 'f', 'e', 'r', 'r', 'y', 'a', 's', 'i', 'd', 'e', 't', 'a', 'p', 'i', 'r', 't', 'r', 'o', 'l', 'l', 'u', 'n', 'i', 'f', 'y', 'r', 'e', 'b', 'u', 's', 'b', 'o', 'o', 's', 't', 't', 'r', 'u', 's', 's', 's', 'i', 'e', 'g', 'e', 't', 'i', 'g', 'e', 'r', 'b', 'a', 'n', 'a', 'l', 's', 'l', 'u', 'm', 'p', 'c', 'r', 'a', 'n', 'k', 'g', 'o', 'r', 'g', 'e', 'q', 'u', 'e', 'r', 'y', 'd', 'r', 'i', 'n', 'k', 'f', 'a', 'v', 'o', 'r', 'a', 'b', 'b', 'e', 'y', 't', 'a', 'n', 'g', 'y', 'p', 'a', 'n', 'i', 'c', 's', 'o', 'l', 'a', 'r', 's', 'h', 'i', 'r', 'e', 'p', 'r', 'o', 'x', 'y', 'p', 'o', 'i', 'n', 't', 'r', 'o', 'b', 'o', 't', 'p', 'r', 'i', 'c', 'k', 'w', 'i', 'n', 'c', 'e', 'c', 'r', 'i', 'm', 'p', 'k', 'n', 'o', 'l', 'l', 's', 'u', 'g', 'a', 'r', 'w', 'h', 'a', 'c', 'k', 'm', 'o', 'u', 'n', 't', 'p', 'e', 'r', 'k', 'y', 'c', 'o', 'u', 'l', 'd', 'w', 'r', 'u', 'n', 'g', 'l', 'i', 'g', 'h', 't', 't', 'h', 'o', 's', 'e', 'm', 'o', 'i', 's', 't', 's', 'h', 'a', 'r', 'd', 'p', 'l', 'e', 'a', 't', 'a', 'l', 'o', 'f', 't', 's', 'k', 'i', 'l', 'l', 'e', 'l', 'd', 'e', 'r', 'f', 'r', 'a', 'm', 'e', 'h', 'u', 'm', 'o', 'r', 'p', 'a', 'u', 's', 'e', 'u', 'l', 'c', 'e', 'r', 'u', 'l', 't', 'r', 'a', 'r', 'o', 'b', 'i', 'n', 'c', 'y', 'n', 'i', 'c', 'a', 'r', 'o', 'm', 'a', 'c', 'a', 'u', 'l', 'k', 's', 'h', 'a', 'k', 'e', 'd', 'o', 'd', 'g', 'e', 's', 'w', 'i', 'l', 'l', 't', 'a', 'c', 'i', 't', 'o', 't', 'h', 'e', 'r', 't', 'h', 'o', 'r', 'n', 't', 'r', 'o', 'v', 'e', 'b', 'l', 'o', 'k', 'e', 'v', 'i', 'v', 'i', 'd', 's', 'p', 'i', 'l', 'l', 'c', 'h', 'a', 'n', 't', 'c', 'h', 'o', 'k', 'e', 'r', 'u', 'p', 'e', 'e', 'n', 'a', 's', 't', 'y', 'm', 'o', 'u', 'r', 'n', 'a', 'h', 'e', 'a', 'd', 'b', 'r', 'i', 'n', 'e', 'c', 'l', 'o', 't', 'h', 'h', 'o', 'a', 'r', 'd', 's', 'w', 'e', 'e', 't', 'm', 'o', 'n', 't', 'h', 'l', 'a', 'p', 's', 'e', 'w', 'a', 't', 'c', 'h', 't', 'o', 'd', 'a', 'y', 'f', 'o', 'c', 'u', 's', 's', 'm', 'e', 'l', 't', 't', 'e', 'a', 's', 'e', 'c', 'a', 't', 'e', 'r', 'm', 'o', 'v', 'i', 'e', 's', 'a', 'u', 't', 'e', 'a', 'l', 'l', 'o', 'w', 'r', 'e', 'n', 'e', 'w', 't', 'h', 'e', 'i', 'r', 's', 'l', 'o', 's', 'h', 'p', 'u', 'r', 'g', 'e', 'c', 'h', 'e', 's', 't', 'd', 'e', 'p', 'o', 't', 'e', 'p', 'o', 'x', 'y', 'n', 'y', 'm', 'p', 'h', 'f', 'o', 'u', 'n', 'd', 's', 'h', 'a', 'l', 'l', 'h', 'a', 'r', 'r', 'y', 's', 't', 'o', 'v', 'e', 'l', 'o', 'w', 'l', 'y', 's', 'n', 'o', 'u', 't', 't', 'r', 'o', 'p', 'e', 'f', 'e', 'w', 'e', 'r', 's', 'h', 'a', 'w', 'l', 'n', 'a', 't', 'a', 'l', 'c', 'o', 'm', 'm', 'a', 'f', 'o', 'r', 'a', 'y', 's', 'c', 'a', 'r', 'e', 's', 't', 'a', 'i', 'r', 'b', 'l', 'a', 'c', 'k', 's', 'q', 'u', 'a', 'd', 'r', 'o', 'y', 'a', 'l', 'c', 'h', 'u', 'n', 'k', 'm', 'i', 'n', 'c', 'e', 's', 'l', 'a', 'v', 'e', 's', 'h', 'a', 'm', 'e', 'c', 'h', 'e', 'e', 'k', 'a', 'm', 'p', 'l', 'e', 'f', 'l', 'a', 'i', 'r', 'f', 'o', 'y', 'e', 'r', 'c', 'a', 'r', 'g', 'o', 'o', 'x', 'i', 'd', 'e', 'p', 'l', 'a', 'n', 't', 'o', 'l', 'i', 'v', 'e', 'i', 'n', 'e', 'r', 't', 'a', 's', 'k', 'e', 'w', 'h', 'e', 'i', 's', 't', 's', 'h', 'o', 'w', 'n', 'z', 'e', 's', 't', 'y', 'h', 'a', 's', 't', 'y', 't', 'r', 'a', 's', 'h', 'f', 'e', 'l', 'l', 'a', 'l', 'a', 'r', 'v', 'a', 'f', 'o', 'r', 'g', 'o', 's', 't', 'o', 'r', 'y', 'h', 'a', 'i', 'r', 'y', 't', 'r', 'a', 'i', 'n', 'h', 'o', 'm', 'e', 'r', 'b', 'a', 'd', 'g', 'e', 'm', 'i', 'd', 's', 't', 'c', 'a', 'n', 'n', 'y', 'f', 'e', 't', 'u', 's', 'b', 'u', 't', 'c', 'h', 'f', 'a', 'r', 'c', 'e', 's', 'l', 'u', 'n', 'g', 't', 'i', 'p', 's', 'y', 'm', 'e', 't', 'a', 'l', 'y', 'i', 'e', 'l', 'd', 'd', 'e', 'l', 'v', 'e', 'b', 'e', 'i', 'n', 'g', 's', 'c', 'o', 'u', 'r', 'g', 'l', 'a', 's', 's', 'g', 'a', 'm', 'e', 'r', 's', 'c', 'r', 'a', 'p', 'm', 'o', 'n', 'e', 'y', 'h', 'i', 'n', 'g', 'e', 'a', 'l', 'b', 'u', 'm', 'v', 'o', 'u', 'c', 'h', 'a', 's', 's', 'e', 't', 't', 'i', 'a', 'r', 'a', 'c', 'r', 'e', 'p', 't', 'b', 'a', 'y', 'o', 'u', 'a', 't', 'o', 'l', 'l', 'm', 'a', 'n', 'o', 'r', 'c', 'r', 'e', 'a', 'k', 's', 'h', 'o', 'w', 'y', 'p', 'h', 'a', 's', 'e', 'f', 'r', 'o', 't', 'h', 'd', 'e', 'p', 't', 'h', 'g', 'l', 'o', 'o', 'm', 'f', 'l', 'o', 'o', 'd', 't', 'r', 'a', 'i', 't', 'g', 'i', 'r', 't', 'h', 'p', 'i', 'e', 't', 'y', 'p', 'a', 'y', 'e', 'r', 'g', 'o', 'o', 's', 'e', 'f', 'l', 'o', 'a', 't', 'd', 'o', 'n', 'o', 'r', 'a', 't', 'o', 'n', 'e', 'p', 'r', 'i', 'm', 'o', 'a', 'p', 'r', 'o', 'n', 'b', 'l', 'o', 'w', 'n', 'c', 'a', 'c', 'a', 'o', 'l', 'o', 's', 'e', 'r', 'i', 'n', 'p', 'u', 't', 'g', 'l', 'o', 'a', 't', 'a', 'w', 'f', 'u', 'l', 'b', 'r', 'i', 'n', 'k', 's', 'm', 'i', 't', 'e', 'b', 'e', 'a', 'd', 'y', 'r', 'u', 's', 't', 'y', 'r', 'e', 't', 'r', 'o', 'd', 'r', 'o', 'l', 'l', 'g', 'a', 'w', 'k', 'y', 'h', 'u', 't', 'c', 'h', 'p', 'i', 'n', 't', 'o', 'g', 'a', 'i', 'l', 'y', 'e', 'g', 'r', 'e', 't', 'l', 'i', 'l', 'a', 'c', 's', 'e', 'v', 'e', 'r', 'f', 'i', 'e', 'l', 'd', 'f', 'l', 'u', 'f', 'f', 'h', 'y', 'd', 'r', 'o', 'f', 'l', 'a', 'c', 'k', 'a', 'g', 'a', 'p', 'e', 'v', 'o', 'i', 'c', 'e', 's', 't', 'e', 'a', 'd', 's', 't', 'a', 'l', 'k', 'b', 'e', 'r', 't', 'h', 'm', 'a', 'd', 'a', 'm', 'n', 'i', 'g', 'h', 't', 'b', 'l', 'a', 'n', 'd', 'l', 'i', 'v', 'e', 'r', 'w', 'e', 'd', 'g', 'e', 'a', 'u', 'g', 'u', 'r', 'r', 'o', 'o', 'm', 'y', 'w', 'a', 'c', 'k', 'y', 'f', 'l', 'o', 'c', 'k', 'a', 'n', 'g', 'r', 'y', 'b', 'o', 'b', 'b', 'y', 't', 'r', 'i', 't', 'e', 'a', 'p', 'h', 'i', 'd', 't', 'r', 'y', 's', 't', 'm', 'i', 'd', 'g', 'e', 'p', 'o', 'w', 'e', 'r', 'e', 'l', 'o', 'p', 'e', 'c', 'i', 'n', 'c', 'h', 'm', 'o', 't', 't', 'o', 's', 't', 'o', 'm', 'p', 'u', 'p', 's', 'e', 't', 'b', 'l', 'u', 'f', 'f', 'c', 'r', 'a', 'm', 'p', 'q', 'u', 'a', 'r', 't', 'c', 'o', 'y', 'l', 'y', 'y', 'o', 'u', 't', 'h', 'r', 'h', 'y', 'm', 'e', 'b', 'u', 'g', 'g', 'y', 'a', 'l', 'i', 'e', 'n', 's', 'm', 'e', 'a', 'r', 'u', 'n', 'f', 'i', 't', 'p', 'a', 't', 't', 'y', 'c', 'l', 'i', 'n', 'g', 'g', 'l', 'e', 'a', 'n', 'l', 'a', 'b', 'e', 'l', 'h', 'u', 'n', 'k', 'y', 'k', 'h', 'a', 'k', 'i', 'p', 'o', 'k', 'e', 'r', 'g', 'r', 'u', 'e', 'l', 't', 'w', 'i', 'c', 'e', 't', 'w', 'a', 'n', 'g', 's', 'h', 'r', 'u', 'g', 't', 'r', 'e', 'a', 't', 'u', 'n', 'l', 'i', 't', 'w', 'a', 's', 't', 'e', 'm', 'e', 'r', 'i', 't', 'w', 'o', 'v', 'e', 'n', 'o', 'c', 't', 'a', 'l', 'n', 'e', 'e', 'd', 'y', 'c', 'l', 'o', 'w', 'n', 'w', 'i', 'd', 'o', 'w', 'i', 'r', 'o', 'n', 'y', 'r', 'u', 'd', 'e', 'r', 'g', 'a', 'u', 'z', 'e', 'c', 'h', 'i', 'e', 'f', 'o', 'n', 's', 'e', 't', 'p', 'r', 'i', 'z', 'e', 'f', 'u', 'n', 'g', 'i', 'c', 'h', 'a', 'r', 'm', 'g', 'u', 'l', 'l', 'y', 'i', 'n', 't', 'e', 'r', 'w', 'h', 'o', 'o', 'p', 't', 'a', 'u', 'n', 't', 'l', 'e', 'e', 'r', 'y', 'c', 'l', 'a', 's', 's', 't', 'h', 'e', 'm', 'e', 'l', 'o', 'f', 't', 'y', 't', 'i', 'b', 'i', 'a', 'b', 'o', 'o', 'z', 'e', 'a', 'l', 'p', 'h', 'a', 't', 'h', 'y', 'm', 'e', 'e', 'c', 'l', 'a', 't', 'd', 'o', 'u', 'b', 't', 'p', 'a', 'r', 'e', 'r', 'c', 'h', 'u', 't', 'e', 's', 't', 'i', 'c', 'k', 't', 'r', 'i', 'c', 'e', 'a', 'l', 'i', 'k', 'e', 's', 'o', 'o', 't', 'h', 'r', 'e', 'c', 'a', 'p', 's', 'a', 'i', 'n', 't', 'l', 'i', 'e', 'g', 'e', 'g', 'l', 'o', 'r', 'y', 'g', 'r', 'a', 't', 'e', 'a', 'd', 'm', 'i', 't', 'b', 'r', 'i', 's', 'k', 's', 'o', 'g', 'g', 'y', 'u', 's', 'u', 'r', 'p', 's', 'c', 'a', 'l', 'd', 's', 'c', 'o', 'r', 'n', 'l', 'e', 'a', 'v', 'e', 't', 'w', 'i', 'n', 'e', 's', 't', 'i', 'n', 'g', 'b', 'o', 'u', 'g', 'h', 'm', 'a', 'r', 's', 'h', 's', 'l', 'o', 't', 'h', 'd', 'a', 'n', 'd', 'y', 'v', 'i', 'g', 'o', 'r', 'h', 'o', 'w', 'd', 'y', 'e', 'n', 'j', 'o', 'y', 'v', 'a', 'l', 'i', 'd', 'i', 'o', 'n', 'i', 'c', 'e', 'q', 'u', 'a', 'l', 'u', 'n', 's', 'e', 't', 'f', 'l', 'o', 'o', 'r', 'c', 'a', 't', 'c', 'h', 's', 'p', 'a', 'd', 'e', 's', 't', 'e', 'i', 'n', 'e', 'x', 'i', 's', 't', 'q', 'u', 'i', 'r', 'k', 'd', 'e', 'n', 'i', 'm', 'g', 'r', 'o', 'v', 'e', 's', 'p', 'i', 'e', 'l', 'm', 'u', 'm', 'm', 'y', 'f', 'a', 'u', 'l', 't', 'f', 'o', 'g', 'g', 'y', 'f', 'l', 'o', 'u', 't', 'c', 'a', 'r', 'r', 'y', 's', 'n', 'e', 'a', 'k', 'l', 'i', 'b', 'e', 'l', 'w', 'a', 'l', 't', 'z', 'a', 'p', 't', 'l', 'y', 'p', 'i', 'n', 'e', 'y', 'i', 'n', 'e', 'p', 't', 'a', 'l', 'o', 'u', 'd', 'p', 'h', 'o', 't', 'o', 'd', 'r', 'e', 'a', 'm', 's', 't', 'a', 'l', 'e', 'v', 'o', 'm', 'i', 't', 'o', 'm', 'b', 'r', 'e', 'f', 'a', 'n', 'n', 'y', 'u', 'n', 'i', 't', 'e', 's', 'n', 'a', 'r', 'l', 'b', 'a', 'k', 'e', 'r', 't', 'h', 'e', 'r', 'e', 'g', 'l', 'y', 'p', 'h', 'p', 'o', 'o', 'c', 'h', 'h', 'i', 'p', 'p', 'y', 's', 'p', 'e', 'l', 'l', 'f', 'o', 'l', 'l', 'y', 'l', 'o', 'u', 's', 'e', 'g', 'u', 'l', 'c', 'h', 'v', 'a', 'u', 'l', 't', 'g', 'o', 'd', 'l', 'y', 't', 'h', 'r', 'e', 'w', 'f', 'l', 'e', 'e', 't', 'g', 'r', 'a', 'v', 'e', 'i', 'n', 'a', 'n', 'e', 's', 'h', 'o', 'c', 'k', 'c', 'r', 'a', 'v', 'e', 's', 'p', 'i', 't', 'e', 'v', 'a', 'l', 'v', 'e', 's', 'k', 'i', 'm', 'p', 'c', 'l', 'a', 'i', 'm', 'r', 'a', 'i', 'n', 'y', 'm', 'u', 's', 't', 'y', 'p', 'i', 'q', 'u', 'e', 'd', 'a', 'd', 'd', 'y', 'q', 'u', 'a', 's', 'i', 'a', 'r', 'i', 's', 'e', 'a', 'g', 'i', 'n', 'g', 'v', 'a', 'l', 'e', 't', 'o', 'p', 'i', 'u', 'm', 'a', 'v', 'e', 'r', 't', 's', 't', 'u', 'c', 'k', 'r', 'e', 'c', 'u', 't', 'm', 'u', 'l', 'c', 'h', 'g', 'e', 'n', 'r', 'e', 'p', 'l', 'u', 'm', 'e', 'r', 'i', 'f', 'l', 'e', 'c', 'o', 'u', 'n', 't', 'i', 'n', 'c', 'u', 'r', 't', 'o', 't', 'a', 'l', 'w', 'r', 'e', 's', 't', 'm', 'o', 'c', 'h', 'a', 'd', 'e', 't', 'e', 'r', 's', 't', 'u', 'd', 'y', 'l', 'o', 'v', 'e', 'r', 's', 'a', 'f', 'e', 'r', 'r', 'i', 'v', 'e', 't', 'f', 'u', 'n', 'n', 'y', 's', 'm', 'o', 'k', 'e', 'm', 'o', 'u', 'n', 'd', 'u', 'n', 'd', 'u', 'e', 's', 'e', 'd', 'a', 'n', 'p', 'a', 'g', 'a', 'n', 's', 'w', 'i', 'n', 'e', 'g', 'u', 'i', 'l', 'e', 'g', 'u', 's', 't', 'y', 'e', 'q', 'u', 'i', 'p', 't', 'o', 'u', 'g', 'h', 'c', 'a', 'n', 'o', 'e', 'c', 'h', 'a', 'o', 's', 'c', 'o', 'v', 'e', 't', 'h', 'u', 'm', 'a', 'n', 'u', 'd', 'd', 'e', 'r', 'l', 'u', 'n', 'c', 'h', 'b', 'l', 'a', 's', 't', 's', 't', 'r', 'a', 'y', 'm', 'a', 'n', 'g', 'a', 'm', 'e', 'l', 'e', 'e', 'l', 'e', 'f', 't', 'y', 'q', 'u', 'i', 'c', 'k', 'p', 'a', 's', 't', 'e', 'g', 'i', 'v', 'e', 'n', 'o', 'c', 't', 'e', 't', 'r', 'i', 's', 'e', 'n', 'g', 'r', 'o', 'a', 'n', 'l', 'e', 'a', 'k', 'y', 'g', 'r', 'i', 'n', 'd', 'c', 'a', 'r', 'v', 'e', 'l', 'o', 'o', 's', 'e', 's', 'a', 'd', 'l', 'y', 's', 'p', 'i', 'l', 't', 'a', 'p', 'p', 'l', 'e', 's', 'l', 'a', 'c', 'k', 'h', 'o', 'n', 'e', 'y', 'f', 'i', 'n', 'a', 'l', 's', 'h', 'e', 'e', 'n', 'e', 'e', 'r', 'i', 'e', 'm', 'i', 'n', 't', 'y', 's', 'l', 'i', 'c', 'k', 'd', 'e', 'r', 'b', 'y', 'w', 'h', 'a', 'r', 'f', 's', 'p', 'e', 'l', 't', 'c', 'o', 'a', 'c', 'h', 'e', 'r', 'u', 'p', 't', 's', 'i', 'n', 'g', 'e', 'p', 'r', 'i', 'c', 'e', 's', 'p', 'a', 'w', 'n', 'f', 'a', 'i', 'r', 'y', 'j', 'i', 'f', 'f', 'y', 'f', 'i', 'l', 'm', 'y', 's', 't', 'a', 'c', 'k', 'c', 'h', 'o', 's', 'e', 's', 'l', 'e', 'e', 'p', 'a', 'r', 'd', 'o', 'r', 'n', 'a', 'n', 'n', 'y', 'n', 'i', 'e', 'c', 'e', 'w', 'o', 'o', 'z', 'y', 'h', 'a', 'n', 'd', 'y', 'g', 'r', 'a', 'c', 'e', 'd', 'i', 't', 't', 'o', 's', 't', 'a', 'n', 'k', 'c', 'r', 'e', 'a', 'm', 'u', 's', 'u', 'a', 'l', 'd', 'i', 'o', 'd', 'e', 'v', 'a', 'l', 'o', 'r', 'a', 'n', 'g', 'l', 'e', 'n', 'i', 'n', 'j', 'a', 'm', 'u', 'd', 'd', 'y', 'c', 'h', 'a', 's', 'e', 'r', 'e', 'p', 'l', 'y', 'p', 'r', 'o', 'n', 'e', 's', 'p', 'o', 'i', 'l', 'h', 'e', 'a', 'r', 't', 's', 'h', 'a', 'd', 'e', 'd', 'i', 'n', 'e', 'r', 'a', 'r', 's', 'o', 'n', 'o', 'n', 'i', 'o', 'n', 's', 'l', 'e', 'e', 't', 'd', 'o', 'w', 'e', 'l', 'c', 'o', 'u', 'c', 'h', 'p', 'a', 'l', 's', 'y', 'b', 'o', 'w', 'e', 'l', 's', 'm', 'i', 'l', 'e', 'e', 'v', 'o', 'k', 'e', 'c', 'r', 'e', 'e', 'k', 'l', 'a', 'n', 'c', 'e', 'e', 'a', 'g', 'l', 'e', 'i', 'd', 'i', 'o', 't', 's', 'i', 'r', 'e', 'n', 'b', 'u', 'i', 'l', 't', 'e', 'm', 'b', 'e', 'd', 'a', 'w', 'a', 'r', 'd', 'd', 'r', 'o', 's', 's', 'a', 'n', 'n', 'u', 'l', 'g', 'o', 'o', 'd', 'y', 'f', 'r', 'o', 'w', 'n', 'p', 'a', 't', 'i', 'o', 'l', 'a', 'd', 'e', 'n', 'h', 'u', 'm', 'i', 'd', 'e', 'l', 'i', 't', 'e', 'l', 'y', 'm', 'p', 'h', 'e', 'd', 'i', 'f', 'y', 'm', 'i', 'g', 'h', 't', 'r', 'e', 's', 'e', 't', 'v', 'i', 's', 'i', 't', 'g', 'u', 's', 't', 'o', 'p', 'u', 'r', 's', 'e', 'v', 'a', 'p', 'o', 'r', 'c', 'r', 'o', 'c', 'k', 'w', 'r', 'i', 't', 'e', 's', 'u', 'n', 'n', 'y', 'l', 'o', 'a', 't', 'h', 'c', 'h', 'a', 'f', 'f', 's', 'l', 'i', 'd', 'e', 'q', 'u', 'e', 'e', 'r', 'v', 'e', 'n', 'o', 'm', 's', 't', 'a', 'm', 'p', 's', 'o', 'r', 'r', 'y', 's', 't', 'i', 'l', 'l', 'a', 'c', 'o', 'r', 'n', 'a', 'p', 'i', 'n', 'g', 'p', 'u', 's', 'h', 'y', 't', 'a', 'm', 'e', 'r', 'h', 'a', 't', 'e', 'r', 'm', 'a', 'n', 'i', 'a', 'a', 'w', 'o', 'k', 'e', 'b', 'r', 'a', 'w', 'n', 's', 'w', 'i', 'f', 't', 'e', 'x', 'i', 'l', 'e', 'b', 'i', 'r', 'c', 'h', 'l', 'u', 'c', 'k', 'y', 'f', 'r', 'e', 'e', 'r', 'r', 'i', 's', 'k', 'y', 'g', 'h', 'o', 's', 't', 'p', 'l', 'i', 'e', 'r', 'l', 'u', 'n', 'a', 'r', 'w', 'i', 'n', 'c', 'h', 's', 'n', 'a', 'r', 'e', 'n', 'u', 'r', 's', 'e', 'h', 'o', 'u', 's', 'e', 'b', 'o', 'r', 'a', 'x', 'n', 'i', 'c', 'e', 'r', 'l', 'u', 'r', 'c', 'h', 'e', 'x', 'a', 'l', 't', 'a', 'b', 'o', 'u', 't', 's', 'a', 'v', 'v', 'y', 't', 'o', 'x', 'i', 'n', 't', 'u', 'n', 'i', 'c', 'p', 'r', 'i', 'e', 'd', 'i', 'n', 'l', 'a', 'y', 'c', 'h', 'u', 'm', 'p', 'l', 'a', 'n', 'k', 'y', 'c', 'r', 'e', 's', 's', 'e', 'a', 't', 'e', 'r', 'e', 'l', 'u', 'd', 'e', 'c', 'y', 'c', 'l', 'e', 'k', 'i', 't', 't', 'y', 'b', 'o', 'u', 'l', 'e', 'm', 'o', 'r', 'o', 'n', 't', 'e', 'n', 'e', 't', 'p', 'l', 'a', 'c', 'e', 'l', 'o', 'b', 'b', 'y', 'p', 'l', 'u', 's', 'h', 'v', 'i', 'g', 'i', 'l', 'i', 'n', 'd', 'e', 'x', 'b', 'l', 'i', 'n', 'k', 'c', 'l', 'u', 'n', 'g', 'q', 'u', 'a', 'l', 'm', 'c', 'r', 'o', 'u', 'p', 'c', 'l', 'i', 'n', 'k', 'j', 'u', 'i', 'c', 'y', 's', 't', 'a', 'g', 'e', 'd', 'e', 'c', 'a', 'y', 'n', 'e', 'r', 'v', 'e', 'f', 'l', 'i', 'e', 'r', 's', 'h', 'a', 'f', 't', 'c', 'r', 'o', 'o', 'k', 'c', 'l', 'e', 'a', 'n', 'c', 'h', 'i', 'n', 'a', 'r', 'i', 'd', 'g', 'e', 'v', 'o', 'w', 'e', 'l', 'g', 'n', 'o', 'm', 'e', 's', 'n', 'u', 'c', 'k', 'i', 'c', 'i', 'n', 'g', 's', 'p', 'i', 'n', 'y', 'r', 'i', 'g', 'o', 'r', 's', 'n', 'a', 'i', 'l', 'f', 'l', 'o', 'w', 'n', 'r', 'a', 'b', 'i', 'd', 'p', 'r', 'o', 's', 'e', 't', 'h', 'a', 'n', 'k', 'p', 'o', 'p', 'p', 'y', 'b', 'u', 'd', 'g', 'e', 'f', 'i', 'b', 'e', 'r', 'm', 'o', 'l', 'd', 'y', 'd', 'o', 'w', 'd', 'y', 'k', 'n', 'e', 'e', 'l', 't', 'r', 'a', 'c', 'k', 'c', 'a', 'd', 'd', 'y', 'q', 'u', 'e', 'l', 'l', 'd', 'u', 'm', 'p', 'y', 'p', 'a', 'l', 'e', 'r', 's', 'w', 'o', 'r', 'e', 'r', 'e', 'b', 'a', 'r', 's', 'c', 'u', 'b', 'a', 's', 'p', 'l', 'a', 't', 'f', 'l', 'y', 'e', 'r', 'h', 'o', 'r', 'n', 'y', 'm', 'a', 's', 'o', 'n', 'd', 'o', 'i', 'n', 'g', 'o', 'z', 'o', 'n', 'e', 'a', 'm', 'p', 'l', 'y', 'm', 'o', 'l', 'a', 'r', 'o', 'v', 'a', 'r', 'y', 'b', 'e', 's', 'e', 't', 'q', 'u', 'e', 'u', 'e', 'c', 'l', 'i', 'f', 'f', 'm', 'a', 'g', 'i', 'c', 't', 'r', 'u', 'c', 'e', 's', 'p', 'o', 'r', 't', 'f', 'r', 'i', 't', 'z', 'e', 'd', 'i', 'c', 't', 't', 'w', 'i', 'r', 'l', 'v', 'e', 'r', 's', 'e', 'l', 'l', 'a', 'm', 'a', 'e', 'a', 't', 'e', 'n', 'r', 'a', 'n', 'g', 'e', 'w', 'h', 'i', 's', 'k', 'h', 'o', 'v', 'e', 'l', 'r', 'e', 'h', 'a', 'b', 'm', 'a', 'c', 'a', 'w', 's', 'i', 'g', 'm', 'a', 's', 'p', 'o', 'u', 't', 'v', 'e', 'r', 'v', 'e', 's', 'u', 's', 'h', 'i', 'd', 'y', 'i', 'n', 'g', 'f', 'e', 't', 'i', 'd', 'b', 'r', 'a', 'i', 'n', 'b', 'u', 'd', 'd', 'y', 't', 'h', 'u', 'm', 'p', 's', 'c', 'i', 'o', 'n', 'c', 'a', 'n', 'd', 'y', 'c', 'h', 'o', 'r', 'd', 'b', 'a', 's', 'i', 'n', 'm', 'a', 'r', 'c', 'h', 'c', 'r', 'o', 'w', 'd', 'a', 'r', 'b', 'o', 'r', 'g', 'a', 'y', 'l', 'y', 'm', 'u', 's', 'k', 'y', 's', 't', 'a', 'i', 'n', 'd', 'a', 'l', 'l', 'y', 'b', 'l', 'e', 's', 's', 'b', 'r', 'a', 'v', 'o', 's', 't', 'u', 'n', 'g', 't', 'i', 't', 'l', 'e', 'r', 'u', 'l', 'e', 'r', 'k', 'i', 'o', 's', 'k', 'b', 'l', 'o', 'n', 'd', 'e', 'n', 'n', 'u', 'i', 'l', 'a', 'y', 'e', 'r', 'f', 'l', 'u', 'i', 'd', 't', 'a', 't', 't', 'y', 's', 'c', 'o', 'r', 'e', 'c', 'u', 't', 'i', 'e', 'z', 'e', 'b', 'r', 'a', 'b', 'a', 'r', 'g', 'e', 'm', 'a', 't', 'e', 'y', 'b', 'l', 'u', 'e', 'r', 'a', 'i', 'd', 'e', 'r', 's', 'h', 'o', 'o', 'k', 'r', 'i', 'v', 'e', 'r', 'p', 'r', 'i', 'v', 'y', 'b', 'e', 't', 'e', 'l', 'f', 'r', 'i', 's', 'k', 'b', 'o', 'n', 'g', 'o', 'b', 'e', 'g', 'u', 'n', 'a', 'z', 'u', 'r', 'e', 'w', 'e', 'a', 'v', 'e', 'g', 'e', 'n', 'i', 'e', 's', 'o', 'u', 'n', 'd', 'g', 'l', 'o', 'v', 'e', 'b', 'r', 'a', 'i', 'd', 's', 'c', 'o', 'p', 'e', 'w', 'r', 'y', 'l', 'y', 'r', 'o', 'v', 'e', 'r', 'a', 's', 's', 'a', 'y', 'o', 'c', 'e', 'a', 'n', 'b', 'l', 'o', 'o', 'm', 'i', 'r', 'a', 't', 'e', 'l', 'a', 't', 'e', 'r', 'w', 'o', 'k', 'e', 'n', 's', 'i', 'l', 'k', 'y', 'w', 'r', 'e', 'c', 'k', 'd', 'w', 'e', 'l', 't', 's', 'l', 'a', 't', 'e', 's', 'm', 'a', 'c', 'k', 's', 'o', 'l', 'i', 'd', 'a', 'm', 'a', 'z', 'e', 'h', 'a', 'z', 'e', 'l', 'w', 'r', 'i', 's', 't', 'j', 'o', 'l', 'l', 'y', 'g', 'l', 'o', 'b', 'e', 'f', 'l', 'i', 'n', 't', 'r', 'o', 'u', 's', 'e', 'c', 'i', 'v', 'i', 'l', 'v', 'i', 's', 't', 'a', 'r', 'e', 'l', 'a', 'x', 'c', 'o', 'v', 'e', 'r', 'a', 'l', 'i', 'v', 'e', 'b', 'e', 'e', 'c', 'h', 'j', 'e', 't', 't', 'y', 'b', 'l', 'i', 's', 's', 'v', 'o', 'c', 'a', 'l', 'o', 'f', 't', 'e', 'n', 'd', 'o', 'l', 'l', 'y', 'e', 'i', 'g', 'h', 't', 'j', 'o', 'k', 'e', 'r', 's', 'i', 'n', 'c', 'e', 'e', 'v', 'e', 'n', 't', 'e', 'n', 's', 'u', 'e', 's', 'h', 'u', 'n', 't', 'd', 'i', 'v', 'e', 'r', 'p', 'o', 's', 'e', 'r', 'w', 'o', 'r', 's', 't', 's', 'w', 'e', 'e', 'p', 'a', 'l', 'l', 'e', 'y', 'c', 'r', 'e', 'e', 'd', 'a', 'n', 'i', 'm', 'e', 'l', 'e', 'a', 'f', 'y', 'b', 'o', 's', 'o', 'm', 'd', 'u', 'n', 'c', 'e', 's', 't', 'a', 'r', 'e', 'p', 'u', 'd', 'g', 'y', 'w', 'a', 'i', 'v', 'e', 'c', 'h', 'o', 'i', 'r', 's', 't', 'o', 'o', 'd', 's', 'p', 'o', 'k', 'e', 'o', 'u', 't', 'g', 'o', 'd', 'e', 'l', 'a', 'y', 'b', 'i', 'l', 'g', 'e', 'i', 'd', 'e', 'a', 'l', 'c', 'l', 'a', 's', 'p', 's', 'e', 'i', 'z', 'e', 'h', 'o', 't', 'l', 'y', 'l', 'a', 'u', 'g', 'h', 's', 'i', 'e', 'v', 'e', 'b', 'l', 'o', 'c', 'k', 'm', 'e', 'a', 'n', 't', 'g', 'r', 'a', 'p', 'e', 'n', 'o', 'o', 's', 'e', 'h', 'a', 'r', 'd', 'y', 's', 'h', 'i', 'e', 'd', 'd', 'r', 'a', 'w', 'l', 'd', 'a', 'i', 's', 'y', 'p', 'u', 't', 't', 'y', 's', 't', 'r', 'u', 't', 'b', 'u', 'r', 'n', 't', 't', 'u', 'l', 'i', 'p', 'c', 'r', 'i', 'c', 'k', 'i', 'd', 'y', 'l', 'l', 'v', 'i', 'x', 'e', 'n', 'f', 'u', 'r', 'o', 'r', 'g', 'e', 'e', 'k', 'y', 'c', 'o', 'u', 'g', 'h', 'n', 'a', 'i', 'v', 'e', 's', 'h', 'o', 'a', 'l', 's', 't', 'o', 'r', 'k', 'b', 'a', 't', 'h', 'e', 'a', 'u', 'n', 't', 'y', 'c', 'h', 'e', 'c', 'k', 'p', 'r', 'i', 'm', 'e', 'b', 'r', 'a', 's', 's', 'o', 'u', 't', 'e', 'r', 'f', 'u', 'r', 'r', 'y', 'r', 'a', 'z', 'o', 'r', 'e', 'l', 'e', 'c', 't', 'e', 'v', 'i', 'c', 't', 'i', 'm', 'p', 'l', 'y', 'd', 'e', 'm', 'u', 'r', 'q', 'u', 'o', 't', 'a', 'h', 'a', 'v', 'e', 'n', 'c', 'a', 'v', 'i', 'l', 's', 'w', 'e', 'a', 'r', 'c', 'r', 'u', 'm', 'p', 'd', 'o', 'u', 'g', 'h', 'g', 'a', 'v', 'e', 'l', 'w', 'a', 'g', 'o', 'n', 's', 'a', 'l', 'o', 'n', 'n', 'u', 'd', 'g', 'e', 'h', 'a', 'r', 'e', 'm', 'p', 'i', 't', 'c', 'h', 's', 'w', 'o', 'r', 'n', 'p', 'u', 'p', 'i', 'l', 'e', 'x', 'c', 'e', 'l', 's', 't', 'o', 'n', 'y', 'c', 'a', 'b', 'i', 'n', 'u', 'n', 'z', 'i', 'p', 'q', 'u', 'e', 'e', 'n', 't', 'r', 'o', 'u', 't', 'p', 'o', 'l', 'y', 'p', 'e', 'a', 'r', 't', 'h', 's', 't', 'o', 'r', 'm', 'u', 'n', 't', 'i', 'l', 't', 'a', 'p', 'e', 'r', 'e', 'n', 't', 'e', 'r', 'c', 'h', 'i', 'l', 'd', 'a', 'd', 'o', 'p', 't', 'm', 'i', 'n', 'o', 'r', 'f', 'a', 't', 't', 'y', 'h', 'u', 's', 'k', 'y', 'b', 'r', 'a', 'v', 'e', 'f', 'i', 'l', 'e', 't', 's', 'l', 'i', 'm', 'e', 'g', 'l', 'i', 'n', 't', 't', 'r', 'e', 'a', 'd', 's', 't', 'e', 'a', 'l', 'r', 'e', 'g', 'a', 'l', 'g', 'u', 'e', 's', 't', 'e', 'v', 'e', 'r', 'y', 'm', 'u', 'r', 'k', 'y', 's', 'h', 'a', 'r', 'e', 's', 'p', 'o', 'r', 'e', 'h', 'o', 'i', 's', 't', 'b', 'u', 'x', 'o', 'm', 'i', 'n', 'n', 'e', 'r', 'o', 't', 't', 'e', 'r', 'd', 'i', 'm', 'l', 'y', 'l', 'e', 'v', 'e', 'l', 's', 'u', 'm', 'a', 'c', 'd', 'o', 'n', 'u', 't', 's', 't', 'i', 'l', 't', 'a', 'r', 'e', 'n', 'a', 's', 'h', 'e', 'e', 't', 's', 'c', 'r', 'u', 'b', 'f', 'a', 'n', 'c', 'y', 's', 'l', 'i', 'm', 'y', 'p', 'e', 'a', 'r', 'l', 's', 'i', 'l', 'l', 'y', 'p', 'o', 'r', 'c', 'h', 'd', 'i', 'n', 'g', 'o', 's', 'e', 'p', 'i', 'a', 'a', 'm', 'b', 'l', 'e', 's', 'h', 'a', 'd', 'y', 'b', 'r', 'e', 'a', 'd', 'f', 'r', 'i', 'a', 'r', 'r', 'e', 'i', 'g', 'n', 'd', 'a', 'i', 'r', 'y', 'q', 'u', 'i', 'l', 'l', 'c', 'r', 'o', 's', 's', 'b', 'r', 'o', 'o', 'd', 't', 'u', 'b', 'e', 'r', 's', 'h', 'e', 'a', 'r', 'p', 'o', 's', 'i', 't', 'b', 'l', 'a', 'n', 'k', 'v', 'i', 'l', 'l', 'a', 's', 'h', 'a', 'n', 'k', 'p', 'i', 'g', 'g', 'y', 'f', 'r', 'e', 'a', 'k', 'w', 'h', 'i', 'c', 'h', 'a', 'm', 'o', 'n', 'g', 'f', 'e', 'c', 'a', 'l', 's', 'h', 'e', 'l', 'l', 'w', 'o', 'u', 'l', 'd', 'a', 'l', 'g', 'a', 'e', 'l', 'a', 'r', 'g', 'e', 'r', 'a', 'b', 'b', 'i', 'a', 'g', 'o', 'n', 'y', 'a', 'm', 'u', 's', 'e', 'b', 'u', 's', 'h', 'y', 'c', 'o', 'p', 's', 'e', 's', 'w', 'o', 'o', 'n', 'k', 'n', 'i', 'f', 'e', 'p', 'o', 'u', 'c', 'h', 'a', 's', 'c', 'o', 't', 'p', 'l', 'a', 'n', 'e', 'c', 'r', 'o', 'w', 'n', 'u', 'r', 'b', 'a', 'n', 's', 'n', 'i', 'd', 'e', 'r', 'e', 'l', 'a', 'y', 'a', 'b', 'i', 'd', 'e', 'v', 'i', 'o', 'l', 'a', 'r', 'a', 'j', 'a', 'h', 's', 't', 'r', 'a', 'w', 'd', 'i', 'l', 'l', 'y', 'c', 'r', 'a', 's', 'h', 'a', 'm', 'a', 's', 's', 't', 'h', 'i', 'r', 'd', 't', 'r', 'i', 'c', 'k', 't', 'u', 't', 'o', 'r', 'w', 'o', 'o', 'd', 'y', 'b', 'l', 'u', 'r', 'b', 'g', 'r', 'i', 'e', 'f', 'd', 'i', 's', 'c', 'o', 'w', 'h', 'e', 'r', 'e', 's', 'a', 's', 's', 'y', 'b', 'e', 'a', 'c', 'h', 's', 'a', 'u', 'n', 'a', 'c', 'o', 'm', 'i', 'c', 'c', 'l', 'u', 'e', 'd', 'c', 'r', 'e', 'e', 'p', 'c', 'a', 's', 't', 'e', 'g', 'r', 'a', 'z', 'e', 's', 'n', 'u', 'f', 'f', 'f', 'r', 'o', 'c', 'k', 'g', 'o', 'n', 'a', 'd', 'd', 'r', 'u', 'n', 'k', 'p', 'r', 'o', 'n', 'g', 'l', 'u', 'r', 'i', 'd', 's', 't', 'e', 'e', 'l', 'h', 'a', 'l', 'v', 'e', 'b', 'u', 'y', 'e', 'r', 'v', 'i', 'n', 'y', 'l', 'u', 't', 'i', 'l', 'e', 's', 'm', 'e', 'l', 'l', 'a', 'd', 'a', 'g', 'e', 'w', 'o', 'r', 'r', 'y', 't', 'a', 's', 't', 'y', 'l', 'o', 'c', 'a', 'l', 't', 'r', 'a', 'd', 'e', 'f', 'i', 'n', 'c', 'h', 'a', 's', 'h', 'e', 'n', 'm', 'o', 'd', 'a', 'l', 'g', 'a', 'u', 'n', 't', 'c', 'l', 'o', 'v', 'e', 'e', 'n', 'a', 'c', 't', 'a', 'd', 'o', 'r', 'n', 'r', 'o', 'a', 's', 't', 's', 'p', 'e', 'c', 'k', 's', 'h', 'e', 'i', 'k', 'm', 'i', 's', 's', 'y', 'g', 'r', 'u', 'n', 't', 's', 'n', 'o', 'o', 'p', 'p', 'a', 'r', 't', 'y', 't', 'o', 'u', 'c', 'h', 'm', 'a', 'f', 'i', 'a', 'e', 'm', 'c', 'e', 'e', 'a', 'r', 'r', 'a', 'y', 's', 'o', 'u', 't', 'h', 'v', 'a', 'p', 'i', 'd', 'j', 'e', 'l', 'l', 'y', 's', 'k', 'u', 'l', 'k', 'a', 'n', 'g', 's', 't', 't', 'u', 'b', 'a', 'l', 'l', 'o', 'w', 'e', 'r', 'c', 'r', 'e', 's', 't', 's', 'w', 'e', 'a', 't', 'c', 'y', 'b', 'e', 'r', 'a', 'd', 'o', 'r', 'e', 't', 'a', 'r', 'd', 'y', 's', 'w', 'a', 'm', 'i', 'n', 'o', 't', 'c', 'h', 'g', 'r', 'o', 'o', 'm', 'r', 'o', 'a', 'c', 'h', 'h', 'i', 't', 'c', 'h', 'y', 'o', 'u', 'n', 'g', 'a', 'l', 'i', 'g', 'n', 'r', 'e', 'a', 'd', 'y', 'f', 'r', 'o', 'n', 'd', 's', 't', 'r', 'a', 'p', 'p', 'u', 'r', 'e', 'e', 'r', 'e', 'a', 'l', 'm', 'v', 'e', 'n', 'u', 'e', 's', 'w', 'a', 'r', 'm', 'o', 'f', 'f', 'e', 'r', 's', 'e', 'v', 'e', 'n', 'd', 'r', 'y', 'e', 'r', 'd', 'i', 'a', 'r', 'y', 'd', 'r', 'y', 'l', 'y', 'd', 'r', 'a', 'n', 'k', 'a', 'c', 'r', 'i', 'd', 'h', 'e', 'a', 'd', 'y', 't', 'h', 'e', 't', 'a', 'j', 'u', 'n', 't', 'o', 'p', 'i', 'x', 'i', 'e', 'q', 'u', 'o', 't', 'h', 'b', 'o', 'n', 'u', 's', 's', 'h', 'a', 'l', 't', 'p', 'e', 'n', 'n', 'e', 'a', 'm', 'e', 'n', 'd', 'd', 'a', 't', 'u', 'm', 'b', 'u', 'i', 'l', 'd', 'p', 'i', 'a', 'n', 'o', 's', 'h', 'e', 'l', 'f', 'l', 'o', 'd', 'g', 'e', 's', 'u', 'i', 'n', 'g', 'r', 'e', 'a', 'r', 'm', 'c', 'o', 'r', 'a', 'l', 'r', 'a', 'm', 'e', 'n', 'w', 'o', 'r', 't', 'h', 'p', 's', 'a', 'l', 'm', 'i', 'n', 'f', 'e', 'r', 'o', 'v', 'e', 'r', 't', 'm', 'a', 'y', 'o', 'r', 'o', 'v', 'o', 'i', 'd', 'g', 'l', 'i', 'd', 'e', 'u', 's', 'a', 'g', 'e', 'p', 'o', 'i', 's', 'e', 'r', 'a', 'n', 'd', 'y', 'c', 'h', 'u', 'c', 'k', 'p', 'r', 'a', 'n', 'k', 'f', 'i', 's', 'h', 'y', 't', 'o', 'o', 't', 'h', 'e', 't', 'h', 'e', 'r', 'd', 'r', 'o', 'v', 'e', 'i', 'd', 'l', 'e', 'r', 's', 'w', 'a', 't', 'h', 's', 't', 'i', 'n', 't', 'w', 'h', 'i', 'l', 'e', 'b', 'e', 'g', 'a', 't', 'a', 'p', 'p', 'l', 'y', 's', 'l', 'a', 'n', 'g', 't', 'a', 'r', 'o', 't', 'r', 'a', 'd', 'a', 'r', 'c', 'r', 'e', 'd', 'o', 'a', 'w', 'a', 'r', 'e', 'c', 'a', 'n', 'o', 'n', 's', 'h', 'i', 'f', 't', 't', 'i', 'm', 'e', 'r', 'b', 'y', 'l', 'a', 'w', 's', 'e', 'r', 'u', 'm', 't', 'h', 'r', 'e', 'e', 's', 't', 'e', 'a', 'k', 'i', 'l', 'i', 'a', 'c', 's', 'h', 'i', 'r', 'k', 'b', 'l', 'u', 'n', 't', 'p', 'u', 'p', 'p', 'y', 'p', 'e', 'n', 'a', 'l', 'j', 'o', 'i', 's', 't', 'b', 'u', 'n', 'n', 'y', 's', 'h', 'a', 'p', 'e', 'b', 'e', 'g', 'e', 't', 'w', 'h', 'e', 'e', 'l', 'a', 'd', 'e', 'p', 't', 's', 't', 'u', 'n', 't', 's', 't', 'o', 'l', 'e', 't', 'o', 'p', 'a', 'z', 'c', 'h', 'o', 'r', 'e', 'f', 'l', 'u', 'k', 'e', 'a', 'f', 'o', 'o', 't', 'b', 'l', 'o', 'a', 't', 'b', 'u', 'l', 'l', 'y', 'd', 'e', 'n', 's', 'e', 'c', 'a', 'p', 'e', 'r', 's', 'n', 'e', 'e', 'r', 'b', 'o', 'x', 'e', 'r', 'j', 'u', 'm', 'b', 'o', 'l', 'u', 'n', 'g', 'e', 's', 'p', 'a', 'c', 'e', 'a', 'v', 'a', 'i', 'l', 's', 'h', 'o', 'r', 't', 's', 'l', 'u', 'r', 'p', 'l', 'o', 'y', 'a', 'l', 'f', 'l', 'i', 'r', 't', 'p', 'i', 'z', 'z', 'a', 'c', 'o', 'n', 'c', 'h', 't', 'e', 'm', 'p', 'o', 'd', 'r', 'o', 'o', 'p', 'p', 'l', 'a', 't', 'e', 'b', 'i', 'b', 'l', 'e', 'p', 'l', 'u', 'n', 'k', 'a', 'f', 'o', 'u', 'l', 's', 'a', 'v', 'o', 'y', 's', 't', 'e', 'e', 'p', 'a', 'g', 'i', 'l', 'e', 's', 't', 'a', 'k', 'e', 'd', 'w', 'e', 'l', 'l', 'k', 'n', 'a', 'v', 'e', 'b', 'e', 'a', 'r', 'd', 'a', 'r', 'o', 's', 'e', 'm', 'o', 't', 'i', 'f', 's', 'm', 'a', 's', 'h', 'b', 'r', 'o', 'i', 'l', 'g', 'l', 'a', 'r', 'e', 's', 'h', 'o', 'v', 'e', 'b', 'a', 'g', 'g', 'y', 'm', 'a', 'm', 'm', 'y', 's', 'w', 'a', 'm', 'p', 'a', 'l', 'o', 'n', 'g', 'r', 'u', 'g', 'b', 'y', 'w', 'a', 'g', 'e', 'r', 'q', 'u', 'a', 'c', 'k', 's', 'q', 'u', 'a', 't', 's', 'n', 'a', 'k', 'y', 'd', 'e', 'b', 'i', 't', 'm', 'a', 'n', 'g', 'e', 's', 'k', 'a', 't', 'e', 'n', 'i', 'n', 't', 'h', 'j', 'o', 'u', 's', 't', 't', 'r', 'a', 'm', 'p', 's', 'p', 'u', 'r', 'n', 'm', 'e', 'd', 'a', 'l', 'm', 'i', 'c', 'r', 'o', 'r', 'e', 'b', 'e', 'l', 'f', 'l', 'a', 'n', 'k', 'l', 'e', 'a', 'r', 'n', 'n', 'a', 'd', 'i', 'r', 'm', 'a', 'p', 'l', 'e', 'c', 'o', 'm', 'f', 'y', 'r', 'e', 'm', 'i', 't', 'g', 'r', 'u', 'f', 'f', 'e', 's', 't', 'e', 'r', 'l', 'e', 'a', 's', 't', 'm', 'o', 'g', 'u', 'l', 'f', 'e', 't', 'c', 'h', 'c', 'a', 'u', 's', 'e', 'o', 'a', 'k', 'e', 'n', 'a', 'g', 'l', 'o', 'w', 'm', 'e', 'a', 't', 'y', 'g', 'a', 'f', 'f', 'e', 's', 'h', 'y', 'l', 'y', 'r', 'a', 'c', 'e', 'r', 'p', 'r', 'o', 'w', 'l', 't', 'h', 'i', 'e', 'f', 's', 't', 'e', 'r', 'n', 'p', 'o', 'e', 's', 'y', 'r', 'o', 'c', 'k', 'y', 't', 'w', 'e', 'e', 't', 'w', 'a', 'i', 's', 't', 's', 'p', 'i', 'r', 'e', 'g', 'r', 'o', 'p', 'e', 'h', 'a', 'v', 'o', 'c', 'p', 'a', 't', 's', 'y', 't', 'r', 'u', 'l', 'y', 'f', 'o', 'r', 't', 'y', 'd', 'e', 'i', 't', 'y', 'u', 'n', 'c', 'l', 'e', 's', 'w', 'i', 's', 'h', 'g', 'i', 'v', 'e', 'r', 'p', 'r', 'e', 'e', 'n', 'b', 'e', 'v', 'e', 'l', 'l', 'e', 'm', 'u', 'r', 'd', 'r', 'a', 'f', 't', 's', 'l', 'o', 'p', 'e', 'a', 'n', 'n', 'o', 'y', 'l', 'i', 'n', 'g', 'o', 'b', 'l', 'e', 'a', 'k', 'd', 'i', 't', 't', 'y', 'c', 'u', 'r', 'l', 'y', 'c', 'e', 'd', 'a', 'r', 'd', 'i', 'r', 'g', 'e', 'g', 'r', 'o', 'w', 'n', 'h', 'o', 'r', 'd', 'e', 'd', 'r', 'o', 'o', 'l', 's', 'h', 'u', 'c', 'k', 'c', 'r', 'y', 'p', 't', 'c', 'u', 'm', 'i', 'n', 's', 't', 'o', 'c', 'k', 'g', 'r', 'a', 'v', 'y', 'l', 'o', 'c', 'u', 's', 'w', 'i', 'd', 'e', 'r', 'b', 'r', 'e', 'e', 'd', 'q', 'u', 'i', 't', 'e', 'c', 'h', 'a', 'f', 'e', 'c', 'a', 'c', 'h', 'e', 'b', 'l', 'i', 'm', 'p', 'd', 'e', 'i', 'g', 'n', 'f', 'i', 'e', 'n', 'd', 'l', 'o', 'g', 'i', 'c', 'c', 'h', 'e', 'a', 'p', 'e', 'l', 'i', 'd', 'e', 'r', 'i', 'g', 'i', 'd', 'f', 'a', 'l', 's', 'e', 'r', 'e', 'n', 'a', 'l', 'p', 'e', 'n', 'c', 'e', 'r', 'o', 'w', 'd', 'y', 's', 'h', 'o', 'o', 't', 'b', 'l', 'a', 'z', 'e', 'e', 'n', 'v', 'o', 'y', 'p', 'o', 's', 's', 'e', 'b', 'r', 'i', 'e', 'f', 'n', 'e', 'v', 'e', 'r', 'a', 'b', 'o', 'r', 't', 'm', 'o', 'u', 's', 'e', 'm', 'u', 'c', 'k', 'y', 's', 'u', 'l', 'k', 'y', 'f', 'i', 'e', 'r', 'y', 'm', 'e', 'd', 'i', 'a', 't', 'r', 'u', 'n', 'k', 'y', 'e', 'a', 's', 't', 'c', 'l', 'e', 'a', 'r', 's', 'k', 'u', 'n', 'k', 's', 'c', 'a', 'l', 'p', 'b', 'i', 't', 't', 'y', 'c', 'i', 'd', 'e', 'r', 'k', 'o', 'a', 'l', 'a', 'd', 'u', 'v', 'e', 't', 's', 'e', 'g', 'u', 'e', 'c', 'r', 'e', 'm', 'e', 's', 'u', 'p', 'e', 'r', 'g', 'r', 'i', 'l', 'l', 'a', 'f', 't', 'e', 'r', 'o', 'w', 'n', 'e', 'r', 'e', 'm', 'b', 'e', 'r', 'r', 'e', 'a', 'c', 'h', 'n', 'o', 'b', 'l', 'y', 'e', 'm', 'p', 't', 'y', 's', 'p', 'e', 'e', 'd', 'g', 'i', 'p', 's', 'y', 'r', 'e', 'c', 'u', 'r', 's', 'm', 'o', 'c', 'k', 'd', 'r', 'e', 'a', 'd', 'm', 'e', 'r', 'g', 'e', 'b', 'u', 'r', 's', 't', 'k', 'a', 'p', 'p', 'a', 'a', 'm', 'i', 't', 'y', 's', 'h', 'a', 'k', 'y', 'h', 'o', 'v', 'e', 'r', 'c', 'a', 'r', 'o', 'l', 's', 'n', 'o', 'r', 't', 's', 'y', 'n', 'o', 'd', 'f', 'a', 'i', 'n', 't', 'h', 'a', 'u', 'n', 't', 'f', 'l', 'o', 'u', 'r', 'c', 'h', 'a', 'i', 'r', 'd', 'e', 't', 'o', 'x', 's', 'h', 'r', 'e', 'w', 't', 'e', 'n', 's', 'e', 'p', 'l', 'i', 'e', 'd', 'q', 'u', 'a', 'r', 'k', 'b', 'u', 'r', 'l', 'y', 'n', 'o', 'v', 'e', 'l', 'w', 'a', 'x', 'e', 'n', 's', 't', 'o', 'i', 'c', 'j', 'e', 'r', 'k', 'y', 'b', 'l', 'i', 't', 'z', 'b', 'e', 'e', 'f', 'y', 'l', 'y', 'r', 'i', 'c', 'h', 'u', 's', 's', 'y', 't', 'o', 'w', 'e', 'l', 'q', 'u', 'i', 'l', 't', 'b', 'e', 'l', 'o', 'w', 'b', 'i', 'n', 'g', 'o', 'w', 'i', 's', 'p', 'y', 'b', 'r', 'a', 's', 'h', 's', 'c', 'o', 'n', 'e', 't', 'o', 'a', 's', 't', 'e', 'a', 's', 'e', 'l', 's', 'a', 'u', 'c', 'y', 'v', 'a', 'l', 'u', 'e', 's', 'p', 'i', 'c', 'e', 'h', 'o', 'n', 'o', 'r', 'r', 'o', 'u', 't', 'e', 's', 'h', 'a', 'r', 'p', 'b', 'a', 'w', 'd', 'y', 'r', 'a', 'd', 'i', 'i', 's', 'k', 'u', 'l', 'l', 'p', 'h', 'o', 'n', 'y', 'i', 's', 's', 'u', 'e', 'l', 'a', 'g', 'e', 'r', 's', 'w', 'e', 'l', 'l', 'u', 'r', 'i', 'n', 'e', 'g', 'a', 's', 's', 'y', 't', 'r', 'i', 'a', 'l', 'f', 'l', 'o', 'r', 'a', 'u', 'p', 'p', 'e', 'r', 'l', 'a', 't', 'c', 'h', 'w', 'i', 'g', 'h', 't', 'b', 'r', 'i', 'c', 'k', 'r', 'e', 't', 'r', 'y', 'h', 'o', 'l', 'l', 'y', 'd', 'e', 'c', 'a', 'l', 'g', 'r', 'a', 's', 's', 's', 'h', 'a', 'c', 'k', 'd', 'o', 'g', 'm', 'a', 'm', 'o', 'v', 'e', 'r', 'd', 'e', 'f', 'e', 'r', 's', 'o', 'b', 'e', 'r', 'o', 'p', 't', 'i', 'c', 'c', 'r', 'i', 'e', 'r', 'v', 'y', 'i', 'n', 'g', 'n', 'o', 'm', 'a', 'd', 'f', 'l', 'u', 't', 'e', 'h', 'i', 'p', 'p', 'o', 's', 'h', 'a', 'r', 'k', 'd', 'r', 'i', 'e', 'r', 'o', 'b', 'e', 's', 'e', 'b', 'u', 'g', 'l', 'e', 't', 'a', 'w', 'n', 'y', 'c', 'h', 'a', 'l', 'k', 'f', 'e', 'a', 's', 't', 'r', 'u', 'd', 'd', 'y', 'p', 'e', 'd', 'a', 'l', 's', 'c', 'a', 'r', 'f', 'c', 'r', 'u', 'e', 'l', 'b', 'l', 'e', 'a', 't', 't', 'i', 'd', 'a', 'l', 's', 'l', 'u', 's', 'h', 's', 'e', 'm', 'e', 'n', 'w', 'i', 'n', 'd', 'y', 'd', 'u', 's', 't', 'y', 's', 'a', 'l', 'l', 'y', 'i', 'g', 'l', 'o', 'o', 'n', 'e', 'r', 'd', 'y', 'j', 'e', 'w', 'e', 'l', 's', 'h', 'o', 'n', 'e', 'w', 'h', 'a', 'l', 'e', 'h', 'y', 'm', 'e', 'n', 'a', 'b', 'u', 's', 'e', 'f', 'u', 'g', 'u', 'e', 'e', 'l', 'b', 'o', 'w', 'c', 'r', 'u', 'm', 'b', 'p', 'a', 'n', 's', 'y', 'w', 'e', 'l', 's', 'h', 's', 'y', 'r', 'u', 'p', 't', 'e', 'r', 's', 'e', 's', 'u', 'a', 'v', 'e', 'g', 'a', 'm', 'u', 't', 's', 'w', 'u', 'n', 'g', 'd', 'r', 'a', 'k', 'e', 'f', 'r', 'e', 'e', 'd', 'a', 'f', 'i', 'r', 'e', 's', 'h', 'i', 'r', 't', 'g', 'r', 'o', 'u', 't', 'o', 'd', 'd', 'l', 'y', 't', 'i', 't', 'h', 'e', 'p', 'l', 'a', 'i', 'd', 'd', 'u', 'm', 'm', 'y', 'b', 'r', 'o', 'o', 'm', 'b', 'l', 'i', 'n', 'd', 't', 'o', 'r', 'c', 'h', 'e', 'n', 'e', 'm', 'y', 'a', 'g', 'a', 'i', 'n', 't', 'y', 'i', 'n', 'g', 'p', 'e', 's', 'k', 'y', 'a', 'l', 't', 'e', 'r', 'g', 'a', 'z', 'e', 'r', 'n', 'o', 'b', 'l', 'e', 'e', 't', 'h', 'o', 's', 'b', 'r', 'i', 'd', 'e', 'e', 'x', 't', 'o', 'l', 'd', 'e', 'c', 'o', 'r', 'h', 'o', 'b', 'b', 'y', 'b', 'e', 'a', 's', 't', 'i', 'd', 'i', 'o', 'm', 'u', 't', 't', 'e', 'r', 't', 'h', 'e', 's', 'e', 's', 'i', 'x', 't', 'h', 'a', 'l', 'a', 'r', 'm', 'e', 'r', 'a', 's', 'e', 'e', 'l', 'e', 'g', 'y', 's', 'p', 'u', 'n', 'k', 'p', 'i', 'p', 'e', 'r', 's', 'c', 'a', 'l', 'y', 's', 'c', 'o', 'l', 'd', 'h', 'e', 'f', 't', 'y', 'c', 'h', 'i', 'c', 'k', 's', 'o', 'o', 't', 'y', 'c', 'a', 'n', 'a', 'l', 'w', 'h', 'i', 'n', 'y', 's', 'l', 'a', 's', 'h', 'q', 'u', 'a', 'k', 'e', 'j', 'o', 'i', 'n', 't', 's', 'w', 'e', 'p', 't', 'p', 'r', 'u', 'd', 'e', 'h', 'e', 'a', 'v', 'y', 'w', 'i', 'e', 'l', 'd', 'f', 'e', 'm', 'm', 'e', 'l', 'a', 's', 's', 'o', 'm', 'a', 'i', 'z', 'e', 's', 'h', 'a', 'l', 'e', 's', 'c', 'r', 'e', 'w', 's', 'p', 'r', 'e', 'e', 's', 'm', 'o', 'k', 'y', 'w', 'h', 'i', 'f', 'f', 's', 'c', 'e', 'n', 't', 'g', 'l', 'a', 'd', 'e', 's', 'p', 'e', 'n', 't', 'p', 'r', 'i', 's', 'm', 's', 't', 'o', 'k', 'e', 'r', 'i', 'p', 'e', 'r', 'o', 'r', 'b', 'i', 't', 'c', 'o', 'c', 'o', 'a', 'g', 'u', 'i', 'l', 't', 'h', 'u', 'm', 'u', 's', 's', 'h', 'u', 's', 'h', 't', 'a', 'b', 'l', 'e', 's', 'm', 'i', 'r', 'k', 'w', 'r', 'o', 'n', 'g', 'n', 'o', 'i', 's', 'y', 'a', 'l', 'e', 'r', 't', 's', 'h', 'i', 'n', 'y', 'e', 'l', 'a', 't', 'e', 'r', 'e', 's', 'i', 'n', 'w', 'h', 'o', 'l', 'e', 'h', 'u', 'n', 'c', 'h', 'p', 'i', 'x', 'e', 'l', 'p', 'o', 'l', 'a', 'r', 'h', 'o', 't', 'e', 'l', 's', 'w', 'o', 'r', 'd', 'c', 'l', 'e', 'a', 't', 'm', 'a', 'n', 'g', 'o', 'r', 'u', 'm', 'b', 'a', 'p', 'u', 'f', 'f', 'y', 'f', 'i', 'l', 'l', 'y', 'b', 'i', 'l', 'l', 'y', 'l', 'e', 'a', 's', 'h', 'c', 'l', 'o', 'u', 't', 'd', 'a', 'n', 'c', 'e', 'o', 'v', 'a', 't', 'e', 'f', 'a', 'c', 'e', 't', 'c', 'h', 'i', 'l', 'i', 'p', 'a', 'i', 'n', 't', 'l', 'i', 'n', 'e', 'r', 'c', 'u', 'r', 'i', 'o', 's', 'a', 'l', 't', 'y', 'a', 'u', 'd', 'i', 'o', 's', 'n', 'a', 'k', 'e', 'f', 'a', 'b', 'l', 'e', 'c', 'l', 'o', 'a', 'k', 'n', 'a', 'v', 'e', 'l', 's', 'p', 'u', 'r', 't', 'p', 'e', 's', 't', 'o', 'b', 'a', 'l', 'm', 'y', 'f', 'l', 'a', 's', 'h', 'u', 'n', 'w', 'e', 'd', 'e', 'a', 'r', 'l', 'y', 'c', 'h', 'u', 'r', 'n', 'w', 'e', 'e', 'd', 'y', 's', 't', 'u', 'm', 'p', 'l', 'e', 'a', 's', 'e', 'w', 'i', 't', 't', 'y', 'w', 'i', 'm', 'p', 'y', 's', 'p', 'o', 'o', 'f', 's', 'a', 'n', 'e', 'r', 'b', 'l', 'e', 'n', 'd', 's', 'a', 'l', 's', 'a', 't', 'h', 'i', 'c', 'k', 'w', 'a', 'r', 't', 'y', 'm', 'a', 'n', 'i', 'c', 'b', 'l', 'a', 'r', 'e', 's', 'q', 'u', 'i', 'b', 's', 'p', 'o', 'o', 'n', 'p', 'r', 'o', 'b', 'e', 'c', 'r', 'e', 'p', 'e', 'k', 'n', 'a', 'c', 'k', 'f', 'o', 'r', 'c', 'e', 'd', 'e', 'b', 'u', 't', 'o', 'r', 'd', 'e', 'r', 'h', 'a', 's', 't', 'e', 't', 'e', 'e', 't', 'h', 'a', 'g', 'e', 'n', 't', 'w', 'i', 'd', 'e', 'n', 'i', 'c', 'i', 'l', 'y', 's', 'l', 'i', 'c', 'e', 'i', 'n', 'g', 'o', 't', 'c', 'l', 'a', 's', 'h', 'j', 'u', 'r', 'o', 'r', 'b', 'l', 'o', 'o', 'd', 'a', 'b', 'o', 'd', 'e', 't', 'h', 'r', 'o', 'w', 'u', 'n', 'i', 't', 'y', 'p', 'i', 'v', 'o', 't', 's', 'l', 'e', 'p', 't', 't', 'r', 'o', 'o', 'p', 's', 'p', 'a', 'r', 'e', 's', 'e', 'w', 'e', 'r', 'p', 'a', 'r', 's', 'e', 'm', 'o', 'r', 'p', 'h', 'c', 'a', 'c', 't', 'i', 't', 'a', 'c', 'k', 'y', 's', 'p', 'o', 'o', 'l', 'd', 'e', 'm', 'o', 'n', 'm', 'o', 'o', 'd', 'y', 'a', 'n', 'n', 'e', 'x', 'b', 'e', 'g', 'i', 'n', 'f', 'u', 'z', 'z', 'y', 'p', 'a', 't', 'c', 'h', 'w', 'a', 't', 'e', 'r', 'l', 'u', 'm', 'p', 'y', 'a', 'd', 'm', 'i', 'n', 'o', 'm', 'e', 'g', 'a', 'l', 'i', 'm', 'i', 't', 't', 'a', 'b', 'b', 'y', 'm', 'a', 'c', 'h', 'o', 'a', 'i', 's', 'l', 'e', 's', 'k', 'i', 'f', 'f', 'b', 'a', 's', 'i', 's', 'p', 'l', 'a', 'n', 'k', 'v', 'e', 'r', 'g', 'e', 'b', 'o', 't', 'c', 'h', 'c', 'r', 'a', 'w', 'l', 'l', 'o', 'u', 's', 'y', 's', 'l', 'a', 'i', 'n', 'c', 'u', 'b', 'i', 'c', 'r', 'a', 'i', 's', 'e', 'w', 'r', 'a', 'c', 'k', 'g', 'u', 'i', 'd', 'e', 'f', 'o', 'i', 's', 't', 'c', 'a', 'm', 'e', 'o', 'u', 'n', 'd', 'e', 'r', 'a', 'c', 't', 'o', 'r', 'r', 'e', 'v', 'u', 'e', 'f', 'r', 'a', 'u', 'd', 'h', 'a', 'r', 'p', 'y', 's', 'c', 'o', 'o', 'p', 'c', 'l', 'i', 'm', 'b', 'r', 'e', 'f', 'e', 'r', 'o', 'l', 'd', 'e', 'n', 'c', 'l', 'e', 'r', 'k', 'd', 'e', 'b', 'a', 'r', 't', 'a', 'l', 'l', 'y', 'e', 't', 'h', 'i', 'c', 'c', 'a', 'i', 'r', 'n', 't', 'u', 'l', 'l', 'e', 'g', 'h', 'o', 'u', 'l', 'h', 'i', 'l', 'l', 'y', 'c', 'r', 'u', 'd', 'e', 'a', 'p', 'a', 'r', 't', 's', 'c', 'a', 'l', 'e', 'o', 'l', 'd', 'e', 'r', 'p', 'l', 'a', 'i', 'n', 's', 'p', 'e', 'r', 'm', 'b', 'r', 'i', 'n', 'y', 'a', 'b', 'b', 'o', 't', 'r', 'e', 'r', 'u', 'n', 'q', 'u', 'e', 's', 't', 'c', 'r', 'i', 's', 'p', 'b', 'o', 'u', 'n', 'd', 'b', 'e', 'f', 'i', 't', 'd', 'r', 'a', 'w', 'n', 's', 'u', 'i', 't', 'e', 'i', 't', 'c', 'h', 'y', 'c', 'h', 'e', 'e', 'r', 'b', 'a', 'g', 'e', 'l', 'g', 'u', 'e', 's', 's', 'b', 'r', 'o', 'a', 'd', 'a', 'x', 'i', 'o', 'm', 'c', 'h', 'a', 'r', 'd', 'c', 'a', 'p', 'u', 't', 'l', 'e', 'a', 'n', 't', 'h', 'a', 'r', 's', 'h', 'c', 'u', 'r', 's', 'e', 'p', 'r', 'o', 'u', 'd', 's', 'w', 'i', 'n', 'g', 'o', 'p', 'i', 'n', 'e', 't', 'a', 's', 't', 'e', 'l', 'u', 'p', 'u', 's', 'g', 'u', 'm', 'b', 'o', 'm', 'i', 'n', 'e', 'r', 'g', 'r', 'e', 'e', 'n', 'c', 'h', 'a', 's', 'm', 'l', 'i', 'p', 'i', 'd', 't', 'o', 'p', 'i', 'c', 'a', 'r', 'm', 'o', 'r', 'b', 'r', 'u', 's', 'h', 'c', 'r', 'a', 'n', 'e', 'm', 'u', 'r', 'a', 'l', 'a', 'b', 'l', 'e', 'd', 'h', 'a', 'b', 'i', 't', 'b', 'o', 's', 's', 'y', 'm', 'a', 'k', 'e', 'r', 'd', 'u', 's', 'k', 'y', 'd', 'i', 'z', 'z', 'y', 'l', 'i', 't', 'h', 'e', 'b', 'r', 'o', 'o', 'k', 'j', 'a', 'z', 'z', 'y', 'f', 'i', 'f', 't', 'y', 's', 'e', 'n', 's', 'e', 'g', 'i', 'a', 'n', 't', 's', 'u', 'r', 'l', 'y', 'l', 'e', 'g', 'a', 'l', 'f', 'a', 't', 'a', 'l', 'f', 'l', 'u', 'n', 'k', 'b', 'e', 'g', 'a', 'n', 'p', 'r', 'u', 'n', 'e', 's', 'm', 'a', 'l', 'l', 's', 'l', 'a', 'n', 't', 's', 'c', 'o', 'f', 'f', 't', 'o', 'r', 'u', 's', 'n', 'i', 'n', 'n', 'y', 'c', 'o', 'v', 'e', 'y', 'v', 'i', 'p', 'e', 'r', 't', 'a', 'k', 'e', 'n', 'm', 'o', 'r', 'a', 'l', 'v', 'o', 'g', 'u', 'e', 'o', 'w', 'i', 'n', 'g', 't', 'o', 'k', 'e', 'n', 'e', 'n', 't', 'r', 'y', 'b', 'o', 'o', 't', 'h', 'v', 'o', 't', 'e', 'r', 'c', 'h', 'i', 'd', 'e', 'e', 'l', 'f', 'i', 'n', 'e', 'b', 'o', 'n', 'y', 'n', 'e', 'i', 'g', 'h', 'm', 'i', 'n', 'i', 'm', 'm', 'e', 'l', 'o', 'n', 'k', 'n', 'e', 'e', 'd', 'd', 'e', 'c', 'o', 'y', 'v', 'o', 'i', 'l', 'a', 'a', 'n', 'k', 'l', 'e', 'a', 'r', 'r', 'o', 'w', 'm', 'u', 's', 'h', 'y', 't', 'r', 'i', 'b', 'e', 'c', 'e', 'a', 's', 'e', 'e', 'a', 'g', 'e', 'r', 'b', 'i', 'r', 't', 'h', 'g', 'r', 'a', 'p', 'h', 'o', 'd', 'd', 'e', 'r', 't', 'e', 'r', 'r', 'a', 'w', 'e', 'i', 'r', 'd', 't', 'r', 'i', 'e', 'd', 'c', 'l', 'a', 'c', 'k', 'c', 'o', 'l', 'o', 'r', 'r', 'o', 'u', 'g', 'h', 'w', 'e', 'i', 'g', 'h', 'u', 'n', 'c', 'u', 't', 'l', 'a', 'd', 'l', 'e', 's', 't', 'r', 'i', 'p', 'c', 'r', 'a', 'f', 't', 'm', 'i', 'n', 'u', 's', 'd', 'i', 'c', 'e', 'y', 't', 'i', 't', 'a', 'n', 'l', 'u', 'c', 'i', 'd', 'v', 'i', 'c', 'a', 'r', 'd', 'r', 'e', 's', 's', 'd', 'i', 't', 'c', 'h', 'g', 'y', 'p', 's', 'y', 'p', 'a', 's', 't', 'a', 't', 'a', 'f', 'f', 'y', 'f', 'l', 'a', 'm', 'e', 's', 'w', 'o', 'o', 'p', 'a', 'l', 'o', 'o', 'f', 's', 'i', 'g', 'h', 't', 'b', 'r', 'o', 'k', 'e', 't', 'e', 'a', 'r', 'y', 'c', 'h', 'a', 'r', 't', 's', 'i', 'x', 't', 'y', 'w', 'o', 'r', 'd', 'y', 's', 'h', 'e', 'e', 'r', 'l', 'e', 'p', 'e', 'r', 'n', 'o', 's', 'e', 'y', 'b', 'u', 'l', 'g', 'e', 's', 'a', 'v', 'o', 'r', 'c', 'l', 'a', 'm', 'p', 'f', 'u', 'n', 'k', 'y', 'f', 'o', 'a', 'm', 'y', 't', 'o', 'x', 'i', 'c', 'b', 'r', 'a', 'n', 'd', 'p', 'l', 'u', 'm', 'b', 'd', 'i', 'n', 'g', 'y', 'b', 'u', 't', 't', 'e', 'd', 'r', 'i', 'l', 'l', 't', 'r', 'i', 'p', 'e', 'b', 'i', 'c', 'e', 'p', 't', 'e', 'n', 'o', 'r', 'k', 'r', 'i', 'l', 'l', 'w', 'o', 'r', 's', 'e', 'd', 'r', 'a', 'm', 'a', 'h', 'y', 'e', 'n', 'a', 't', 'h', 'i', 'n', 'k', 'r', 'a', 't', 'i', 'o', 'c', 'o', 'b', 'r', 'a', 'b', 'a', 's', 'i', 'l', 's', 'c', 'r', 'u', 'm', 'b', 'u', 's', 'e', 'd', 'p', 'h', 'o', 'n', 'e', 'c', 'o', 'u', 'r', 't', 'c', 'a', 'm', 'e', 'l', 'p', 'r', 'o', 'o', 'f', 'h', 'e', 'a', 'r', 'd', 'a', 'n', 'g', 'e', 'l', 'p', 'e', 't', 'a', 'l', 'p', 'o', 'u', 't', 'y', 't', 'h', 'r', 'o', 'b', 'm', 'a', 'y', 'b', 'e', 'f', 'e', 't', 'a', 'l', 's', 'p', 'r', 'i', 'g', 's', 'p', 'i', 'n', 'e', 's', 'h', 'o', 'u', 't', 'c', 'a', 'd', 'e', 't', 'm', 'a', 'c', 'r', 'o', 'd', 'o', 'd', 'g', 'y', 's', 'a', 't', 'y', 'r', 'r', 'a', 'r', 'e', 'r', 'b', 'i', 'n', 'g', 'e', 't', 'r', 'e', 'n', 'd', 'n', 'u', 't', 't', 'y', 'l', 'e', 'a', 'p', 't', 'a', 'm', 'i', 's', 's', 's', 'p', 'l', 'i', 't', 'm', 'y', 'r', 'r', 'h', 'w', 'i', 'd', 't', 'h', 's', 'o', 'n', 'a', 'r', 't', 'o', 'w', 'e', 'r', 'b', 'a', 'r', 'o', 'n', 'f', 'e', 'v', 'e', 'r', 'w', 'a', 'v', 'e', 'r', 's', 'p', 'a', 'r', 'k', 'b', 'e', 'l', 'i', 'e', 's', 'l', 'o', 'o', 'p', 'e', 'x', 'p', 'e', 'l', 's', 'm', 'o', 't', 'e', 'b', 'a', 'l', 'e', 'r', 'a', 'b', 'o', 'v', 'e', 'n', 'o', 'r', 't', 'h', 'w', 'a', 'f', 'e', 'r', 's', 'c', 'a', 'n', 't', 'f', 'r', 'i', 'l', 'l', 'a', 'w', 'a', 's', 'h', 's', 'n', 'a', 'c', 'k', 's', 'c', 'o', 'w', 'l', 'f', 'r', 'a', 'i', 'l', 'd', 'r', 'i', 'f', 't', 'l', 'i', 'm', 'b', 'o', 'f', 'e', 'n', 'c', 'e', 'm', 'o', 't', 'e', 'l', 'o', 'u', 'n', 'c', 'e', 'w', 'r', 'e', 'a', 'k', 'r', 'e', 'v', 'e', 'l', 't', 'a', 'l', 'o', 'n', 'p', 'r', 'i', 'o', 'r', 'k', 'n', 'e', 'l', 't', 'c', 'e', 'l', 'l', 'o', 'f', 'l', 'a', 'k', 'e', 'd', 'e', 'b', 'u', 'g', 'a', 'n', 'o', 'd', 'e', 'c', 'r', 'i', 'm', 'e', 's', 'a', 'l', 'v', 'e', 's', 'c', 'o', 'u', 't', 'i', 'm', 'b', 'u', 'e', 'p', 'i', 'n', 'k', 'y', 's', 't', 'a', 'v', 'e', 'v', 'a', 'g', 'u', 'e', 'c', 'h', 'o', 'c', 'k', 'f', 'i', 'g', 'h', 't', 'v', 'i', 'd', 'e', 'o', 's', 't', 'o', 'n', 'e', 't', 'e', 'a', 'c', 'h', 'c', 'l', 'e', 'f', 't', 'f', 'r', 'o', 's', 't', 'p', 'r', 'a', 'w', 'n', 'b', 'o', 'o', 't', 'y', 't', 'w', 'i', 's', 't', 'a', 'p', 'n', 'e', 'a', 's', 't', 'i', 'f', 'f', 'p', 'l', 'a', 'z', 'a', 'l', 'e', 'd', 'g', 'e', 't', 'w', 'e', 'a', 'k', 'b', 'o', 'a', 'r', 'd', 'g', 'r', 'a', 'n', 't', 'm', 'e', 'd', 'i', 'c', 'b', 'a', 'c', 'o', 'n', 'c', 'a', 'b', 'l', 'e', 'b', 'r', 'a', 'w', 'l', 's', 'l', 'u', 'n', 'k', 'r', 'a', 's', 'p', 'y', 'f', 'o', 'r', 'u', 'm', 'd', 'r', 'o', 'n', 'e', 'w', 'o', 'm', 'e', 'n', 'm', 'u', 'c', 'u', 's', 'b', 'o', 'a', 's', 't', 't', 'o', 'd', 'd', 'y', 'c', 'o', 'v', 'e', 'n', 't', 'u', 'm', 'o', 'r', 't', 'r', 'u', 'e', 'r', 'w', 'r', 'a', 't', 'h', 's', 't', 'a', 'l', 'l', 's', 't', 'e', 'a', 'm', 'a', 'x', 'i', 'a', 'l', 'p', 'u', 'r', 'e', 'r', 'd', 'a', 'i', 'l', 'y', 't', 'r', 'a', 'i', 'l', 'n', 'i', 'c', 'h', 'e', 'm', 'e', 'a', 'l', 'y', 'j', 'u', 'i', 'c', 'e', 'n', 'y', 'l', 'o', 'n', 'p', 'l', 'u', 'm', 'p', 'm', 'e', 'r', 'r', 'y', 'f', 'l', 'a', 'i', 'l', 'p', 'a', 'p', 'a', 'l', 'w', 'h', 'e', 'a', 't', 'b', 'e', 'r', 'r', 'y', 'c', 'o', 'w', 'e', 'r', 'e', 'r', 'e', 'c', 't', 'b', 'r', 'u', 't', 'e', 'l', 'e', 'g', 'g', 'y', 's', 'n', 'i', 'p', 'e', 's', 'i', 'n', 'e', 'w', 's', 'k', 'i', 'e', 'r', 'p', 'e', 'n', 'n', 'y', 'j', 'u', 'm', 'p', 'y', 'r', 'a', 'l', 'l', 'y', 'u', 'm', 'b', 'r', 'a', 's', 'c', 'a', 'r', 'y', 'm', 'o', 'd', 'e', 'm', 'g', 'r', 'o', 's', 's', 'a', 'v', 'i', 'a', 'n', 'g', 'r', 'e', 'e', 'd', 's', 'a', 't', 'i', 'n', 't', 'o', 'n', 'i', 'c', 'p', 'a', 'r', 'k', 'a', 's', 'n', 'i', 'f', 'f', 'l', 'i', 'v', 'i', 'd', 's', 't', 'a', 'r', 'k', 't', 'r', 'u', 'm', 'p', 'g', 'i', 'd', 'd', 'y', 'r', 'e', 'u', 's', 'e', 't', 'a', 'b', 'o', 'o', 'a', 'v', 'o', 'i', 'd', 'q', 'u', 'o', 't', 'e', 'd', 'e', 'v', 'i', 'l', 'l', 'i', 'k', 'e', 'n', 'g', 'l', 'o', 's', 's', 'g', 'a', 'y', 'e', 'r', 'b', 'e', 'r', 'e', 't', 'n', 'o', 'i', 's', 'e', 'g', 'l', 'a', 'n', 'd', 'd', 'e', 'a', 'l', 't', 's', 'l', 'i', 'n', 'g', 'r', 'u', 'm', 'o', 'r', 'o', 'p', 'e', 'r', 'a', 't', 'h', 'i', 'g', 'h', 't', 'o', 'n', 'g', 'a', 'f', 'l', 'a', 'r', 'e', 'w', 'o', 'u', 'n', 'd', 'w', 'h', 'i', 't', 'e', 'b', 'u', 'l', 'k', 'y', 'e', 't', 'u', 'd', 'e', 'h', 'o', 'r', 's', 'e', 'c', 'i', 'r', 'c', 'a', 'p', 'a', 'd', 'd', 'y', 'i', 'n', 'b', 'o', 'x', 'f', 'i', 'z', 'z', 'y', 'g', 'r', 'a', 'i', 'n', 'e', 'x', 'e', 'r', 't', 's', 'u', 'r', 'g', 'e', 'g', 'l', 'e', 'a', 'm', 'b', 'e', 'l', 'l', 'e', 's', 'a', 'l', 'v', 'o', 'c', 'r', 'u', 's', 'h', 'f', 'r', 'u', 'i', 't', 's', 'a', 'p', 'p', 'y', 't', 'a', 'k', 'e', 'r', 't', 'r', 'a', 'c', 't', 'o', 'v', 'i', 'n', 'e', 's', 'p', 'i', 'k', 'y', 'f', 'r', 'a', 'n', 'k', 'r', 'e', 'e', 'd', 'y', 'f', 'i', 'l', 't', 'h', 's', 'p', 'a', 's', 'm', 'h', 'e', 'a', 'v', 'e', 'm', 'a', 'm', 'b', 'o', 'r', 'i', 'g', 'h', 't', 'c', 'l', 'a', 'n', 'k', 't', 'r', 'u', 's', 't', 'l', 'u', 'm', 'e', 'n', 'b', 'o', 'r', 'n', 'e', 's', 'p', 'o', 'o', 'k', 's', 'a', 'u', 'c', 'e', 'a', 'm', 'b', 'e', 'r', 'l', 'a', 't', 'h', 'e', 'c', 'a', 'r', 'a', 't', 'c', 'o', 'r', 'e', 'r', 'd', 'i', 'r', 't', 'y', 's', 'l', 'y', 'l', 'y', 'a', 'f', 'f', 'i', 'x', 'a', 'l', 'l', 'o', 'y', 't', 'a', 'i', 'n', 't', 's', 'h', 'e', 'e', 'p', 'k', 'i', 'n', 'k', 'y', 'w', 'o', 'o', 'l', 'y', 'm', 'a', 'u', 'v', 'e', 'f', 'l', 'u', 'n', 'g', 'y', 'a', 'c', 'h', 't', 'f', 'r', 'i', 'e', 'd', 'q', 'u', 'a', 'i', 'l', 'b', 'r', 'u', 'n', 't', 'g', 'r', 'i', 'm', 'y', 'c', 'u', 'r', 'v', 'y', 'c', 'a', 'g', 'e', 'y', 'r', 'i', 'n', 's', 'e', 'd', 'e', 'u', 'c', 'e', 's', 't', 'a', 't', 'e', 'g', 'r', 'a', 's', 'p', 'm', 'i', 'l', 'k', 'y', 'b', 'i', 's', 'o', 'n', 'g', 'r', 'a', 'f', 't', 's', 'a', 'n', 'd', 'y', 'b', 'a', 's', 't', 'e', 'f', 'l', 'a', 's', 'k', 'h', 'e', 'd', 'g', 'e', 'g', 'i', 'r', 'l', 'y', 's', 'w', 'a', 's', 'h', 'b', 'o', 'n', 'e', 'y', 'c', 'o', 'u', 'p', 'e', 'e', 'n', 'd', 'o', 'w', 'a', 'b', 'h', 'o', 'r', 'w', 'e', 'l', 'c', 'h', 'b', 'l', 'a', 'd', 'e', 't', 'i', 'g', 'h', 't', 'g', 'e', 'e', 's', 'e', 'm', 'i', 's', 'e', 'r', 'm', 'i', 'r', 't', 'h', 'c', 'l', 'o', 'u', 'd', 'c', 'a', 'b', 'a', 'l', 'l', 'e', 'e', 'c', 'h', 'c', 'l', 'o', 's', 'e', 't', 'e', 'n', 't', 'h', 'p', 'e', 'c', 'a', 'n', 'd', 'r', 'o', 'i', 't', 'g', 'r', 'a', 'i', 'l', 'c', 'l', 'o', 'n', 'e', 'g', 'u', 'i', 's', 'e', 'r', 'a', 'l', 'p', 'h', 't', 'a', 'n', 'g', 'o', 'b', 'i', 'd', 'd', 'y', 's', 'm', 'i', 't', 'h', 'm', 'o', 'w', 'e', 'r', 'p', 'a', 'y', 'e', 'e', 's', 'e', 'r', 'i', 'f', 'd', 'r', 'a', 'p', 'e', 'f', 'i', 'f', 't', 'h', 's', 'p', 'a', 'n', 'k', 'g', 'l', 'a', 'z', 'e', 'a', 'l', 'l', 'o', 't', 't', 'r', 'u', 'c', 'k', 'k', 'a', 'y', 'a', 'k', 'v', 'i', 'r', 'u', 's', 't', 'e', 's', 't', 'y', 't', 'e', 'p', 'e', 'e', 'f', 'u', 'l', 'l', 'y', 'z', 'o', 'n', 'a', 'l', 'm', 'e', 't', 'r', 'o', 'c', 'u', 'r', 'r', 'y', 'g', 'r', 'a', 'n', 'd', 'b', 'a', 'n', 'j', 'o', 'a', 'x', 'i', 'o', 'n', 'b', 'e', 'z', 'e', 'l', 'o', 'c', 'c', 'u', 'r', 'c', 'h', 'a', 'i', 'n', 'n', 'a', 's', 'a', 'l', 'g', 'o', 'o', 'e', 'y', 'f', 'i', 'l', 'e', 'r', 'b', 'r', 'a', 'c', 'e', 'a', 'l', 'l', 'a', 'y', 'p', 'u', 'b', 'i', 'c', 'r', 'a', 'v', 'e', 'n', 'p', 'l', 'e', 'a', 'd', 'g', 'n', 'a', 's', 'h', 'f', 'l', 'a', 'k', 'y', 'm', 'u', 'n', 'c', 'h', 'd', 'u', 'l', 'l', 'y', 'e', 'k', 'i', 'n', 'g', 't', 'h', 'i', 'n', 'g', 's', 'l', 'i', 'n', 'k', 'h', 'u', 'r', 'r', 'y', 't', 'h', 'e', 'f', 't', 's', 'h', 'o', 'r', 'n', 'p', 'y', 'g', 'm', 'y', 'r', 'a', 'n', 'c', 'h', 'w', 'r', 'i', 'n', 'g', 'l', 'e', 'm', 'o', 'n', 's', 'h', 'o', 'r', 'e', 'm', 'a', 'm', 'm', 'a', 'f', 'r', 'o', 'z', 'e', 'n', 'e', 'w', 'e', 'r', 's', 't', 'y', 'l', 'e', 'm', 'o', 'o', 's', 'e', 'a', 'n', 't', 'i', 'c', 'd', 'r', 'o', 'w', 'n', 'v', 'e', 'g', 'a', 'n', 'c', 'h', 'e', 's', 's', 'g', 'u', 'p', 'p', 'y', 'u', 'n', 'i', 'o', 'n', 'l', 'e', 'v', 'e', 'r', 'l', 'o', 'r', 'r', 'y', 'i', 'm', 'a', 'g', 'e', 'c', 'a', 'b', 'b', 'y', 'd', 'r', 'u', 'i', 'd', 'e', 'x', 'a', 'c', 't', 't', 'r', 'u', 't', 'h', 'd', 'o', 'p', 'e', 'y', 's', 'p', 'e', 'a', 'r', 'c', 'r', 'i', 'e', 'd', 'c', 'h', 'i', 'm', 'e', 'c', 'r', 'o', 'n', 'y', 's', 't', 'u', 'n', 'k', 't', 'i', 'm', 'i', 'd', 'b', 'a', 't', 'c', 'h', 'g', 'a', 'u', 'g', 'e', 'r', 'o', 't', 'o', 'r', 'c', 'r', 'a', 'c', 'k', 'c', 'u', 'r', 'v', 'e', 'l', 'a', 't', 't', 'e', 'w', 'i', 't', 'c', 'h', 'b', 'u', 'n', 'c', 'h', 'r', 'e', 'p', 'e', 'l', 'a', 'n', 'v', 'i', 'l', 's', 'o', 'a', 'p', 'y', 'm', 'e', 't', 'e', 'r', 'b', 'r', 'o', 't', 'h', 'm', 'a', 'd', 'l', 'y', 'd', 'r', 'i', 'e', 'd', 's', 'c', 'e', 'n', 'e', 'k', 'n', 'o', 'w', 'n', 'm', 'a', 'g', 'm', 'a', 'r', 'o', 'o', 's', 't', 'w', 'o', 'm', 'a', 'n', 't', 'h', 'o', 'n', 'g', 'p', 'u', 'n', 'c', 'h', 'p', 'a', 's', 't', 'y', 'd', 'o', 'w', 'n', 'y', 'k', 'n', 'e', 'a', 'd', 'w', 'h', 'i', 'r', 'l', 'r', 'a', 'p', 'i', 'd', 'c', 'l', 'a', 'n', 'g', 'a', 'n', 'g', 'e', 'r', 'd', 'r', 'i', 'v', 'e', 'g', 'o', 'o', 'f', 'y', 'e', 'm', 'a', 'i', 'l', 'm', 'u', 's', 'i', 'c', 's', 't', 'u', 'f', 'f', 'b', 'l', 'e', 'e', 'p', 'r', 'i', 'd', 'e', 'r', 'm', 'e', 'c', 'c', 'a', 'f', 'o', 'l', 'i', 'o', 's', 'e', 't', 'u', 'p', 'v', 'e', 'r', 's', 'o', 'q', 'u', 'a', 's', 'h', 'f', 'a', 'u', 'n', 'a', 'g', 'u', 'm', 'm', 'y', 'h', 'a', 'p', 'p', 'y', 'n', 'e', 'w', 'l', 'y', 'f', 'u', 's', 's', 'y', 'r', 'e', 'l', 'i', 'c', 'g', 'u', 'a', 'v', 'a', 'r', 'a', 't', 't', 'y', 'f', 'u', 'd', 'g', 'e', 'f', 'e', 'm', 'u', 'r', 'c', 'h', 'i', 'r', 'p', 'f', 'o', 'r', 't', 'e', 'a', 'l', 'i', 'b', 'i', 'w', 'h', 'i', 'n', 'e', 'p', 'e', 't', 't', 'y', 'g', 'o', 'l', 'l', 'y', 'p', 'l', 'a', 'i', 't', 'f', 'l', 'e', 'c', 'k', 'f', 'e', 'l', 'o', 'n', 'g', 'o', 'u', 'r', 'd', 'b', 'r', 'o', 'w', 'n', 't', 'h', 'r', 'u', 'm', 'f', 'i', 'c', 'u', 's', 's', 't', 'a', 's', 'h', 'd', 'e', 'c', 'r', 'y', 'w', 'i', 's', 'e', 'r', 'j', 'u', 'n', 't', 'a', 'v', 'i', 's', 'o', 'r', 'd', 'a', 'u', 'n', 't', 's', 'c', 'r', 'e', 'e', 'i', 'm', 'p', 'e', 'l', 'a', 'w', 'a', 'i', 't', 'p', 'r', 'e', 's', 's', 'w', 'h', 'o', 's', 'e', 't', 'u', 'r', 'b', 'o', 's', 't', 'o', 'o', 'p', 's', 'p', 'e', 'a', 'k', 'm', 'a', 'n', 'g', 'y', 'e', 'y', 'i', 'n', 'g', 'i', 'n', 'l', 'e', 't', 'c', 'r', 'o', 'n', 'e', 'p', 'u', 'l', 's', 'e', 'm', 'o', 's', 's', 'y', 's', 't', 'a', 'i', 'd', 'h', 'e', 'n', 'c', 'e', 'p', 'i', 'n', 'c', 'h', 't', 'e', 'd', 'd', 'y', 's', 'u', 'l', 'l', 'y', 's', 'n', 'o', 'r', 'e', 'r', 'i', 'p', 'e', 'n', 's', 'n', 'o', 'w', 'y', 'a', 't', 't', 'i', 'c', 'g', 'o', 'i', 'n', 'g', 'l', 'e', 'a', 'c', 'h', 'm', 'o', 'u', 't', 'h', 'h', 'o', 'u', 'n', 'd', 'c', 'l', 'u', 'm', 'p', 't', 'o', 'n', 'a', 'l', 'b', 'i', 'g', 'o', 't', 'p', 'e', 'r', 'i', 'l', 'p', 'i', 'e', 'c', 'e', 'b', 'l', 'a', 'm', 'e', 'h', 'a', 'u', 't', 'e', 's', 'p', 'i', 'e', 'd', 'u', 'n', 'd', 'i', 'd', 'i', 'n', 't', 'r', 'o', 'b', 'a', 's', 'a', 'l', 's', 'h', 'i', 'n', 'e', 'g', 'e', 'c', 'k', 'o', 'r', 'o', 'd', 'e', 'o', 'g', 'u', 'a', 'r', 'd', 's', 't', 'e', 'e', 'r', 'l', 'o', 'a', 'm', 'y', 's', 'c', 'a', 'm', 'p', 's', 'c', 'r', 'a', 'm', 'm', 'a', 'n', 'l', 'y', 'h', 'e', 'l', 'l', 'o', 'v', 'a', 'u', 'n', 't', 'o', 'r', 'g', 'a', 'n', 'f', 'e', 'r', 'a', 'l', 'k', 'n', 'o', 'c', 'k', 'e', 'x', 't', 'r', 'a', 'c', 'o', 'n', 'd', 'o', 'a', 'd', 'a', 'p', 't', 'w', 'i', 'l', 'l', 'y', 'p', 'o', 'l', 'k', 'a', 'r', 'a', 'y', 'o', 'n', 's', 'k', 'i', 'r', 't', 'f', 'a', 'i', 't', 'h', 't', 'o', 'r', 's', 'o', 'm', 'a', 't', 'c', 'h', 'm', 'e', 'r', 'c', 'y', 't', 'e', 'p', 'i', 'd', 's', 'l', 'e', 'e', 'k', 'r', 'i', 's', 'e', 'r', 't', 'w', 'i', 'x', 't', 'p', 'e', 'a', 'c', 'e', 'f', 'l', 'u', 's', 'h', 'c', 'a', 't', 't', 'y', 'l', 'o', 'g', 'i', 'n', 'e', 'j', 'e', 'c', 't', 'r', 'o', 'g', 'e', 'r', 'r', 'i', 'v', 'a', 'l', 'u', 'n', 't', 'i', 'e', 'r', 'e', 'f', 'i', 't', 'a', 'o', 'r', 't', 'a', 'a', 'd', 'u', 'l', 't', 'j', 'u', 'd', 'g', 'e', 'r', 'o', 'w', 'e', 'r', 'a', 'r', 't', 's', 'y', 'r', 'u', 'r', 'a', 'l', 's', 'h', 'a', 'v', 'e' };
string green;
string yellow;
string red;
vector<string> guesses;
























//takes a string as a parameter and returns a char type vector containing that string's lettes.
vector<char> Converter(string convertee) {
    vector<char> v(convertee.begin(), convertee.end());

    return v;
}

//takes the guessed word and the solution word and outputs a string vector of the resulting colors(green, yellow, or red).
vector<string> Colors(string solution, string guess) {
    vector<char> S = Converter(solution);
    vector<char> G = Converter(guess);
    vector<string> colors;

    for (int i = 0; i < 5; i++) {
        if (G[i] == S[0] || G[i] == S[1] || G[i] == S[2] || G[i] == S[3] || G[i] == S[4]) {
            if (G[i] == S[i]) {
                colors.push_back("green");
            }
            else {
                colors.push_back("yellow");
            }
        }
        else {
            colors.push_back("red");
        }
    }
    return colors;
}

bool isViableWord(string toBeChecked) {
    bool viable = false;
    for (int i = 0; i < PossibleSolutions.size(); i++) {
        if (PossibleSolutions[i] == toBeChecked) {
            viable = true;
        }
    }
    return viable;
}

bool doubleLetter(string toBeChecked) {
    bool hasDoubleLetters = false;
    vector <char> letters = Converter(toBeChecked);
    if ((letters[0] == letters[1]) || (letters[0] == letters[2]) || (letters[0] == letters[3]) || (letters[0] == letters[4]) || (letters[1] == letters[2]) || (letters[1] == letters[3]) || (letters[1] == letters[4]) || (letters[2] == letters[3]) || (letters[2] == letters[4]) || (letters[3] == letters[4])) {
        hasDoubleLetters = true;
    }
    return hasDoubleLetters;
}

//needs some work
bool consoleViable(char console) {
    bool yet = false;
    if ((console == 1) || (console == 2) || (console == 3) || (console == 4)) {
        yet = true;
    }
    return yet;
}


//thanks chagptington
bool fourValuesEqual(vector<string>& vec) {
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == "green") {
            count++;
        }
    }
    return count == 4;
}

int whichSpot(vector<string> colors) {
    for (int i = 0; i < colors.size(); i++) {
    int count = 0;
    for (int j = 0; j < colors.size(); j++) {
        if (colors[i] != colors[j]) {
             count++;
             }
        }
        if (count != 1) {
            return i;
        }
    }
    return 0;
}

//The main workhorse method and the most difficult to write. The parameters are confusing, so here's the explanation:
//solution is not actually used in Version 1.0.0, but it will defintely be used later when I implement the automatic solver features.
//guess is simply what word you guessed. It is compared to the possible remaining words based on the colors to figure out which words are still possible.
//RemainingSchmords is what words are remaining. This is for any iteration past the first so the program can build on the work it has already done.
//number is number of guesses. It is used to check if guesses equals one or not. If it doesn't then the char letters array needs modified. May be cut for efficiency later.
//interactive is true in the only feature this version. If true, colors are determined via input. If false, colors are determined by passing solution into the colors function.
//input is only important if interactive is true, it takes the colors the user sees.
vector<string> RemainingWords(string solution, string guess, vector<string>RemainingSchmords, int number, bool interactive, vector<string>input) {
    vector<char> Solution(Converter(solution));
    vector<char> Guess(Converter(guess));
    vector<char>forDebugging = PossibleChars;
    if (number != 1){
        vector<char> T;
        for (int s = 0; s < RemainingSchmords.size(); s++) {
            string var = RemainingSchmords[s];
            vector<char> tran(var.begin(), var.end());
            for (int t = 0; t < 5; t++) {
                T.push_back(tran[t]);
            }
        }
        forDebugging = T;
    }
    
    //insides will be a for loop for each letter of the word, then a check for what color each letter is, then iterating through what remaining words are left and checking whether they
    //are compatable with the color returned for that individual letter. It is brute forcy, but the list of words it has to check through will decrease each time it does it. 
    //i represents the character in the guess being checked while j represents the word in remaining words vector that it is being checked against.


    //something's wrong with this function. It works fine when called to solve for one word, but for some reason when it is called for another word in all 3 of the methods that I try
    //this in it gives the vector subscript soft error. I now know it is because of passing in PossibleSolutions multiple times. 
    //The error was resolved. When using global variables, make a local copy to apply changes to.
    vector<string>colors;
    if (!interactive) {
       colors = Colors(solution, guess);
    }
    else if(interactive){
        colors = input;
    }
    vector<string> strictlyDebug = colors;
    for (int i = 0; i < 5; i++) {
        string color = colors[i];
        if (color == "green") {
            vector<string> TempRemaining;
            vector<char> TempoRemaining;
            for (int j = 0; j < RemainingSchmords.size(); j++) {
                int position = 5 * j + i;
                if (forDebugging[position] == Guess[i]) {
                    string temp = RemainingSchmords[j];
                    TempRemaining.push_back(temp);
                    vector<char> tempo(temp.begin(), temp.end());
                    for (int k = 0; k < 5; k++) {
                        TempoRemaining.push_back(tempo[k]);
                    }
                }
            }
            RemainingSchmords = TempRemaining;
            TempRemaining.clear();
            forDebugging = TempoRemaining;
            TempoRemaining.clear();
        }
        else if (color == "yellow") {

            vector<string> TempRemaining;
            vector<char> TempoRemaining;
            for (int j = 0; j < RemainingSchmords.size(); j++) {
                int position = 5 * j;
                if ((forDebugging[position] == Guess[i] && forDebugging[position+i] != Guess[i]) || (forDebugging[position+1] == Guess[i] && forDebugging[position+i] != Guess[i]) || (forDebugging[position+2] == Guess[i] && forDebugging[position+i] != Guess[i]) || (forDebugging[position+3] == Guess[i] && forDebugging[position+i] != Guess[i]) || (forDebugging[position+4] == Guess[i] && forDebugging[position+i] != guess[i])) {
                    string temp = RemainingSchmords[j];
                    TempRemaining.push_back(temp);
                    vector<char> tempo(temp.begin(), temp.end());
                    for (int k = 0; k < 5; k++) {
                        TempoRemaining.push_back(tempo[k]);
                    }
                }
            }
            RemainingSchmords = TempRemaining;
            TempRemaining.clear();
            forDebugging = TempoRemaining;
            TempoRemaining.clear();
        }
        else if (color == "red") {
            vector<string> TempRemaining;
            vector<char> TempoRemaining;
            for (int j = 0; j < RemainingSchmords.size(); j++) {
                int position = 5 * j;
                if ((forDebugging[position] != Guess[i]) && (forDebugging[position+1] != Guess[i]) && (forDebugging[position+2] != Guess[i]) && (forDebugging[position+3] != Guess[i]) && (forDebugging[position+4] != Guess[i])) {
                    char checker = forDebugging[position];
                    string temp = RemainingSchmords[j];
                    TempRemaining.push_back(temp);
                    vector<char> tempo(temp.begin(), temp.end());
                    for (int k = 0; k < 5; k++) {
                        TempoRemaining.push_back(tempo[k]);
                    }
                }
            }
            RemainingSchmords = TempRemaining;
            TempRemaining.clear();
            forDebugging = TempoRemaining;
            TempoRemaining.clear();
        }
    }
    return RemainingSchmords;
}


string wordsWithLetters(vector<char> letters) {
    string ret;
    int toBeat = 0;
    for (int i = 0; i < PossibleSolutions.size(); i++) {
        string temp = PossibleSolutions[i];
        vector<char> comp(temp.begin(), temp.end());
        int count = 0;
        vector<char> temperer = letters;
        for (int j = letters.size() - 1; j >= 0; j--) {
            for (int k = 0; k < comp.size(); k++) {
                if (letters[j] == comp[k]) {
                    count++;
                    letters.erase(letters.begin() + j);
                    break;
                }
            }
        }
        letters = temperer;
        if(count > toBeat){
            toBeat = count;
            ret = PossibleSolutions[i];
        }
    }
    return ret;
}


string findBestWord1(vector<string> words) {
    int leastWords = words.size();
    if (leastWords == 1) {
        return words[0];
    }
    string guess;
    int sum = 0;
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            vector<string> temp = RemainingWords(words[j], words[i], words, 1, false, { "filler" });
            sum += temp.size();
        }
        int average = sum / words.size();

        //double letters are bad generally so I discouraged them a bit
        if (doubleLetter(words[i]) && words.size() > 8) {
            average = average * 1.25;
        }
        if (average < leastWords) {
            guess = words[i];
            leastWords = average;
        }
        sum = 0;
    }
    return guess;
}


//need to find a way to make it randomly select instead of always doing the first one. 
void SingleSolver() {
    srand(time(0));
    string solution;
    bool IsGuessable = false;
    vector<string> duplicate = PossibleSolutions;
    cout << "What word would you like the bot to solve?" << endl;
    cin >> solution;
    for (int i = 0; i < PossibleSolutions.size(); i++) {
        if (PossibleSolutions[i] == solution) {
            IsGuessable = true;
        }
    }
    if (IsGuessable == false) {
        cout << "That word is not in the set of solutions. Please choose another word." << endl;
        cin >> solution;
    }

    cout << "The bot started with 'raise'." << endl;
    if (solution == "raise") {
        cout << "It was correct! The bot got it in 1 guess." << endl;
        return;
    }
    vector<string>ty1 = RemainingWords(solution, "raise", duplicate, 1, false, {"filler"});
    string nextAttempt = ty1[rand() % ty1.size()];
    cout << "The bot chose " << nextAttempt << " as its next guess."<<endl;
    if (nextAttempt == solution) {
        cout << "That guess was correct! The bot got it in 2 guesses." << endl;
        return;
    }
    vector<string> ty2 = RemainingWords(solution, nextAttempt, ty1, 2, false, {"filler"});

    nextAttempt = ty2[rand() % ty2.size()];
    cout << "The bot chose " << ty2[0] << " as its next guess."<<endl;
    if (ty2[0] == solution) {
        cout << "That guess was correct! The bot got it in 3 guesses." << endl;
        return;
    }
    vector<string> ty3 = RemainingWords(solution, nextAttempt, ty2, 2, false, { "filler" });
    nextAttempt = ty3[rand() % ty3.size()];
    cout << "The bot chose " << nextAttempt << " as its next guess." << endl;
    if (nextAttempt == solution) {
        cout << "That guess was correct! The bot got it in 4 guesses." << endl;
        return;
    }
    vector<string> ty4 = RemainingWords(solution, nextAttempt, ty3, 2, false, { "filler" });
    nextAttempt = ty4[rand() % ty4.size()];
    cout << "The bot chose " << nextAttempt << " as its next guess." << endl;
    if (nextAttempt == solution) {
        cout << "That guess was correct! The bot got it in 5 guesses." << endl;
        return;
    }
    vector<string> ty5 = RemainingWords(solution, nextAttempt, ty4, 2, false, { "filler" });
    nextAttempt = ty5[rand() % ty5.size()];
    cout << "The bot chose " << nextAttempt << " as its next guess." << endl;
    if (nextAttempt == solution) {
        cout << "That guess was correct! The bot got it in 6 guesses." << endl;
        return;
    }
    else {
        cout << "The bot failed to guess the solution.";
        return;
    }
    duplicate.clear();
}


double RandomWord(string firstWord, string currentSolution) {
    srand(time(0));
    double HowMany;
    
    string randomGuess;

        if (currentSolution != firstWord) {
            guesses.push_back("raise");
            vector<string> tire1 = RemainingWords(currentSolution, "raise", PossibleSolutions, 1, false, { "filler" });
            randomGuess = tire1[rand() % tire1.size()];
            guesses.push_back(randomGuess);
            if (randomGuess != currentSolution) {
                vector<string> tire2 = RemainingWords(currentSolution, randomGuess, tire1, 2, false, { "filler" });
                randomGuess = tire2[rand() % tire2.size()];
                guesses.push_back(randomGuess);
                if (randomGuess != currentSolution) {
                    vector<string> tire3 = RemainingWords(currentSolution, randomGuess, tire2, 3, false, { "filler" });
                    randomGuess = tire3[rand() % tire3.size()];
                    guesses.push_back(randomGuess);
                    if (randomGuess != currentSolution) {
                        vector<string> tire4 = RemainingWords(currentSolution, randomGuess, tire3, 4, false, { "filler" });
                        randomGuess = tire4[rand() % tire4.size()];
                        guesses.push_back(randomGuess);
                        if (randomGuess != currentSolution) {
                            vector<string> tire5 = RemainingWords(currentSolution, randomGuess, tire4, 5, false, { "filler" });
                            randomGuess = tire5[rand() % tire5.size()];
                            guesses.push_back(randomGuess);
                            if (randomGuess != currentSolution) {
                                HowMany = 7;
                            }
                            else {
                                HowMany = 6;
                            }
                        }
                        else {
                            HowMany = 5;
                        }
                    }
                    else {
                        HowMany = 4;
                    }
                }
                else {
                    HowMany = 3;
                }
            }
            else {
                HowMany = 2;
            }
        }
        else {
            HowMany = 1;
        }
    return HowMany;
}


//I don't know the best way to handle fails yet, so I'm going to make them equivalent to getting it in 7 guesses for now.
//This thing actually takes forver, so I'm going to elminate all words with double letters in them. 
string BestStartingWord() {
    string bestWord;
    double bestAverage = 7;
    for (int i = 0; i < PossibleSolutions.size(); i++) {
        cout << i + 1 << ", ";
        bool doubleLetters = doubleLetter(PossibleSolutions[i]);
        if (doubleLetters == false) {
            double numberOfOnes = 0;
            double numberOfTwos = 0;
            double numberOfThrees = 0;
            double numberOfFours = 0;
            double numberOfFives = 0;
            double numberOfSixes = 0;
            double numberOfFails = 0;
            double Sum = 0;
            double wordsCompleted = PossibleSolutions.size();
            for (int j = 0; j < PossibleSolutions.size(); j++) {
                double HowMany = RandomWord(PossibleSolutions[i], PossibleSolutions[j]);
                if (HowMany == 1) {
                    numberOfOnes++;
                    Sum += 1;
                }
                else if (HowMany == 2) {
                    numberOfTwos++;
                    Sum += 2;
                }
                else if (HowMany == 3) {
                    numberOfThrees++;
                    Sum += 3;
                }
                else if (HowMany == 4) {
                    numberOfFours++;
                    Sum += 4;
                }
                else if (HowMany == 5) {
                    numberOfFives++;
                    Sum += 5;
                }
                else if (HowMany == 6) {
                    numberOfSixes++;
                    Sum += 6;
                }
                else {
                    numberOfFails++;
                    Sum += 7;
                }
            }
            double Average = Sum / wordsCompleted;
            if (Average < bestAverage) {
                bestAverage = Average;
                bestWord = PossibleSolutions[i];
            }
        }
    }
    return bestWord;
}


//The method that performs the first feature.
void InteractiveHelper() {
    string guess1;
    string color1;
    string color2;
    string color3;
    string color4;
    string color5;
    string winner;
    vector<string> clone = PossibleSolutions;
    cout << endl << "This is the Solving Assistant. It will tell you all of the remaining possible solutions to your daily wordle." << endl;
    cout << endl << "What will your first guess be?" << endl;
    cin >> guess1;
    cout << endl << "Did you get it? yes or no?"<<endl;
    cin >> winner;
    if (winner == "yes") {
        cout << endl << endl << "Good job you defintely didn't cheat!";
        return;
    }
    cout << endl << "Enter the first color as green, yellow, or red" << endl;
    cin >> color1;
    cout << "Enter the second color as green, yellow, or red" << endl;
    cin >> color2;
    cout << "Enter the third color as green, yellow, or red" << endl;
    cin >> color3;
    cout << "Enter the fourth color as green, yellow, or red" << endl;
    cin >> color4;
    cout << "Enter the fifth color as green, yellow, or red" << endl;
    cin >> color5;
    vector<string> inputted{ color1,color2,color3,color4,color5 };
    vector<string> List1 = RemainingWords("sucks", guess1, clone, 1, true, inputted);
    cout << endl << "The remaining possible solutions are:" << endl << endl;
    for (int a = 0; a < List1.size(); a++) {
        cout << List1[a]<<" ";
    }
    cout << endl << endl << "What will your second guess be?" << endl;
    cin >> guess1;
    cout << endl << "Did you get it? yes or no?" << endl;
    cin >> winner;
    if (winner == "yes") {
        cout << endl << endl << "Good job you got it in 2 guesses!";
        return;
    }
    cout << endl << "Enter the first color as green, yellow, or red" << endl;
    cin >> color1;
    cout << "Enter the second color as green, yellow, or red" << endl;
    cin >> color2;
    cout << "Enter the third color as green, yellow, or red" << endl;
    cin >> color3;
    cout << "Enter the fourth color as green, yellow, or red" << endl;
    cin >> color4;
    cout << "Enter the fifth color as green, yellow, or red" << endl;
    cin >> color5;
    inputted = { color1,color2,color3,color4,color5 };
    vector<string> List2 = RemainingWords("sucks", guess1, List1, 2, true, inputted);
    cout << endl << "The remaining possible solutions are:" << endl << endl;
    for (int a = 0; a < List2.size(); a++) {
        cout << List2[a] << " ";
    }
    cout << endl << endl << "What will your third guess be?"<< endl;
    cin >> guess1;
    cout << endl << "Did you get it? yes or no?" << endl;;
    cin >> winner;
    if (winner == "yes") {
        cout << endl << endl << "Good job you got it in 3 guesses!";
        return;
    }
    cout << endl << "Enter the first color as green, yellow, or red" << endl;
    cin >> color1;
    cout << "Enter the second color as green, yellow, or red" << endl;
    cin >> color2;
    cout << "Enter the third color as green, yellow, or red" << endl;
    cin >> color3;
    cout << "Enter the fourth color as green, yellow, or red" << endl;
    cin >> color4;
    cout << "Enter the fifth color as green, yellow, or red" << endl;
    cin >> color5;
    inputted = { color1,color2,color3,color4,color5 };
    vector<string> List3 = RemainingWords("sucks", guess1, List2, 2, true, inputted);
    cout << endl << "The remaining possible solutions are:" << endl << endl;
    for (int a = 0; a < List3.size(); a++) {
        cout << List3[a] << " ";
    }
    cout << endl << endl << "What will your fourth guess be?" << endl;
    cin >> guess1;
    cout << endl << "Did you get it? yes or no?"<<endl;
    cin >> winner;
    if (winner == "yes") {
        cout << endl << endl << "Good job you got it in 4 guesses!";
        return;
    }
    cout << endl << "Enter the first color as green, yellow, or red" << endl;
    cin >> color1;
    cout << "Enter the second color as green, yellow, or red" << endl;
    cin >> color2;
    cout << "Enter the third color as green, yellow, or red" << endl;
    cin >> color3;
    cout << "Enter the fourth color as green, yellow, or red" << endl;
    cin >> color4;
    cout << "Enter the fifth color as green, yellow, or red" << endl;
    cin >> color5;
    inputted = { color1,color2,color3,color4,color5 };
    vector<string> List4 = RemainingWords("sucks", guess1, List3, 2, true, inputted);
    cout << endl << "The remaining possible solutions are:" << endl << endl;
    for (int a = 0; a < List4.size(); a++) {
        cout << List4[a] << " ";
    }
    cout << endl << endl << "What will your fifth guess be?" << endl ;
    cin >> guess1;
    cout << endl << "Did you get it? yes or no?"<<endl;
    cin >> winner;
    if (winner == "yes") {
        cout << endl << endl << "Good job you got it in 5 guesses!";
        return;
    }
    cout << endl << "Enter the first color as green, yellow, or red" << endl;
    cin >> color1;
    cout << "Enter the second color as green, yellow, or red" << endl;
    cin >> color2;
    cout << "Enter the third color as green, yellow, or red" << endl;
    cin >> color3;
    cout << "Enter the fourth color as green, yellow, or red" << endl;
    cin >> color4;
    cout << "Enter the fifth color as green, yellow, or red" << endl;
    cin >> color5;
    inputted = { color1,color2,color3,color4,color5 };
    vector<string> List5 = RemainingWords("sucks", guess1, List4, 2, true, inputted);
    cout << endl << "The remaining possible solutions are:" << endl << endl;
    for (int a = 0; a < List5.size(); a++) {
        cout << List5[a] << " ";
    }
    cout << endl << endl << "What will your sixth guess be?" << endl;
    cin >> guess1;
    cout << endl << "Did you get it? yes or no?"<<endl;
    cin >> winner;
    if (winner == "yes") {
        cout << endl << endl << "Good job you really cut it close!";
        return;
    }
    else {
        cout << "You didn't get it. Better luck next time!";
        return;
    }
}

//solves by choosing the word that will result in the lowest number of average words remaining
int SmartSolver(string solution, string firstWord) {
    vector<string> coloures;
    if (solution == firstWord) {
        return 1;
    }
    guesses.push_back(firstWord);
    string guess;
    coloures = Colors(solution, firstWord);
    vector<string> time1 = RemainingWords(solution, firstWord, PossibleSolutions, 1, true, coloures);
    if (fourValuesEqual(coloures) && time1.size() > 2) {
        vector<char> param;
        int spot = whichSpot(coloures);
        for (int i = 0; i < time1.size(); i++) {
            vector<char> temp(time1[i].begin(), time1[i].end());
            param.push_back(temp[spot]);
        }
        guess = wordsWithLetters(param);
    }
    else {
        guess = findBestWord1(time1);
    }
    guesses.push_back(guess);
    if (guess == solution) {
        return 2;
    }
    coloures = Colors(solution, guess);
    vector<string> time2 = RemainingWords(solution, guess, time1, 2, true, coloures);
    if (fourValuesEqual(coloures) && time2.size() > 2) {
        vector<char> param;
        int spot = whichSpot(coloures);
        for (int i = 0; i < time2.size(); i++) {
            vector<char> temp(time2[i].begin(), time2[i].end());
            param.push_back(temp[spot]);
        }
        guess = wordsWithLetters(param);
    }
    else {
        guess = findBestWord1(time2);
    }
    guesses.push_back(guess);
    if (guess == solution) {
        return 3;
    }
    coloures = Colors(solution, guess);
    vector<string> time3 = RemainingWords(solution, guess, time2, 3, true, coloures);
    if (fourValuesEqual(coloures) && time3.size() > 2) {
        vector<char> param;
        int spot = whichSpot(coloures);
        for (int i = 0; i < time3.size(); i++) {
            vector<char> temp(time3[i].begin(), time3[i].end());
            param.push_back(temp[spot]);
        }
        guess = wordsWithLetters(param);
    }
    else {
        guess = findBestWord1(time3);
    }
    guesses.push_back(guess);
    if (guess == solution) {
        return 4;
    }
    coloures = Colors(solution, guess);
    vector<string> time4 = RemainingWords(solution, guess, time3, 4, true, coloures);
    if (fourValuesEqual(coloures) && time4.size() > 2) {
        vector<char> param;
        int spot = whichSpot(coloures);
        for (int i = 0; i < time4.size(); i++) {
            vector<char> temp(time4[i].begin(), time4[i].end());
            param.push_back(temp[spot]);
        }
        guess = wordsWithLetters(param);
    }
    else {
        guess = findBestWord1(time4);
    }
    guesses.push_back(guess);
    if (guess == solution) {
        return 5; 
    }
    coloures = Colors(solution, guess);
    vector<string> time5 = RemainingWords(solution, guess, time4, 5, true, coloures);
    guess = findBestWord1(time5);
    guesses.push_back(guess);
    if (guess == solution) {
        return 6;
    }

    else {
        return 7;
    }
}


//This is the main method. It is the control panel where everything is called. 
//I'm just going to have it prompt the user for which feature they want and then funnel them to the correct function with a simple switch statement.
int main() {

    int consoleCounter = 0;

  //cout << "This is the Wordle Solver created by Seamus Leonard! This is version 1.0.0, so only the first feature works." << endl << "More features coming soon!" << endl;
    cout << "Enter the number corresponding to what feature you would like to use." << endl;
    cout << "1 - Solving Assitant: Helps you solve your Wordle by giving you all remaining solutions." << endl;
    cout << "2 - Random Single Word Solver: The bot will solve a given word by choosing random possible word." << endl;
    cout << "3 - Smart Single Word Solver: The bot solves a provided word, outputting each guess and how man guesses it took" << endl;
    //cout << "4 - Best Starting Word: Applies feature three to all the solutions to find the best starting word." << endl;
    cout << "4 - Maximum Performance: Applies my best algorithm to each possible solution and provides statistics about its findings." << endl;
    cout << endl;
    int control;
    cin >> control;
    
    while (control == 1 || control == 2 || control == 3 || control == 4) {

        if (control == 1) {
            InteractiveHelper();
            cout << endl << endl << "Enter a feature's corresponding number if you wish to continue. Enter any other number to quit." << endl << endl;
            cin >> control;
        }

        else if (control == 2) {
            cout << endl << "Enter the word would you like the bot to solve." << endl << endl;
            string word;
            cin >> word;
            double ret = RandomWord("raise", word);
            cout << endl;
            for (int i = 0; i < guesses.size(); i++) {
                cout << "The bot guessed: " << guesses[i] << "." << endl;
            }
            guesses.clear();
            cout << endl << "It took the bot " << ret << " guesses.";
            cout << endl << endl << "Enter a feature's corresponding number if you wish to continue. Enter any other number to quit." << endl << endl;
            cin >> control;
        }

        else if (control == 3) {
            cout << endl << "What word would you like the bot to solve?" << endl << endl;
            string word;
            cin >> word;
            int ret = SmartSolver(word,"raise");
            cout << endl;
            for (int i = 0; i < guesses.size(); i++) {
                cout << "The bot guessed: " << guesses[i] << "." << endl;
            }
            cout << endl << "It took the bot " << ret << " guesses.";
            guesses.clear();
            cout << endl << endl << "Enter a feature's corresponding number if you wish to continue. Enter any other number to quit." << endl << endl;
            cin >> control;
        }
  

        /*else if (control == 5) {
            cout << "This will take forever." << endl << endl;
            cout << "The best starting word is: " << BestStartingWord() << ".";
            cout << endl << "Enter a feature's corresponding number if you wish to continue. Enter any other number to quit.";
            cin >> control;
        }*/

        else if (control == 4) {
            srand(time(0));
            cout << endl << "What word would you like the bot to start with. Words with uncommon letters will lead to longer computation time and" << endl << "worse results. The bot likes raise." << endl;
            string firstWord;
            cin >> firstWord;
            cout << "This could take a while." << endl << endl;
            double sum = 0;
            double percent = 0;
            vector<string> clone = PossibleSolutions;
            vector<string> sample;
            for (int ran = 0; ran < 50; ran++) {
                int index = rand() % clone.size();
                sample.push_back(clone[index]);
                clone.erase(clone.begin() + index);
            }
            for (int i = 0; i < sample.size(); i++) {
                cout << sample[i] << " (" << SmartSolver(sample[i],firstWord) << ") ";
                sum += SmartSolver(sample[i],firstWord);
            }
            double average = sum / sample.size();
            cout << endl << "The average number of guesses was " << average << "." << endl;
            sample.clear();
            cout << endl << endl << "Enter a feature's corresponding number if you wish to continue. Enter any other number to quit." << endl << endl;
            cin >> control;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
