# NFLIP

Small program for flipping the sign of numbers readen from the standard input.

## Help

    Usage: nflip [-f][-e] < NUMBERS > NUMBERS
    
    Flip the sign of the numbers read from the standard input. The
    input can contain other characters.
    
       -f : Flip number signs.
       -e : Transform to the spanish number notation.

## Example

Example input without flipping:

    $ hledger --pretty bse
    Balance Sheet With Equity 2024-06-15
    
                                               ║ 2024-06-15 
    ═══════════════════════════════════════════╬════════════
     Assets                                    ║            
    ───────────────────────────────────────────╫────────────
     A:NoCorriente:InmMaterial:216-Mobiliario  ║    858.00€ 
     A:NoCorriente:InmMaterial:217-Informatica ║   4082.00€ 
     A:Corriente:Tesoreria:574-Bancos:BBVA     ║    689.64€ 
    ───────────────────────────────────────────╫────────────
                                               ║   5629.64€ 
    ═══════════════════════════════════════════╬════════════
     Liabilities                               ║            
    ───────────────────────────────────────────╫────────────
    ───────────────────────────────────────────╫────────────
                                               ║            
    ═══════════════════════════════════════════╬════════════
     Equity                                    ║            
    ───────────────────────────────────────────╫────────────
     PN:Capital:100-Social:Member1             ║   3060.00€ 
     PN:Capital:100-Social:Member2             ║   2940.00€ 
    ───────────────────────────────────────────╫────────────
                                               ║   6000.00€ 
    ═══════════════════════════════════════════╬════════════
     Net:                                      ║   -370.36€

Example with flipping and spanish notation.

    $ hledger --pretty bse | nflip -ef
    Balance Sheet With Equity 2024-06-15
    
                                               ║ 2024-06-15 
    ═══════════════════════════════════════════╬════════════
     Assets                                    ║            
    ───────────────────────────────────────────╫────────────
     A:NoCorriente:InmMaterial:216-Mobiliario  ║   -858,00€ 
     A:NoCorriente:InmMaterial:217-Informatica ║  -4082,00€ 
     A:Corriente:Tesoreria:574-Bancos:BBVA     ║   -689,64€ 
    ───────────────────────────────────────────╫────────────
                                               ║  -5629,64€ 
    ═══════════════════════════════════════════╬════════════
     Liabilities                               ║            
    ───────────────────────────────────────────╫────────────
    ───────────────────────────────────────────╫────────────
                                               ║            
    ═══════════════════════════════════════════╬════════════
     Equity                                    ║            
    ───────────────────────────────────────────╫────────────
     PN:Capital:100-Social:Member1             ║  -3060,00€ 
     PN:Capital:100-Social:Member2             ║  -2940,00€ 
    ───────────────────────────────────────────╫────────────
                                               ║  -6000,00€ 
    ═══════════════════════════════════════════╬════════════
     Net:                                      ║    370,36€


## Collaborating

For making bug reports, feature requests and donations visit
one of the following links:

1. [gemini://harkadev.com/oss/](gemini://harkadev.com/oss/)
2. [https://harkadev.com/oss/](https://harkadev.com/oss/)
