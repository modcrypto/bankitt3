// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2018 The BanKitz developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "random.h"
#include "util.h"
#include "utilstrencodings.h"
#include "version.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>


using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
//UpdateTip: new best=000001e3a9376321dbdee64a8bf0717a59119b7e2498f8f69ecab9527f7f5c90  height=26  log2_work=24.840521  tx=27  date=2018-08-18 06:11:19 progress=1.000000  cache=26 time=1534572679
//UpdateTip: new best=00000048e6c897a687474d073d1b913d224fc5826267d18fe90bf36f6fed6f61  height=80  log2_work=28.077972  tx=84  date=2018-08-18 07:42:12 progress=1.000000  cache=10 time=1534578132


static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (26, uint256("000001e3a9376321dbdee64a8bf0717a59119b7e2498f8f69ecab9527f7f5c90"))    
    (80, uint256("00000048e6c897a687474d073d1b913d224fc5826267d18fe90bf36f6fed6f61"))    
;

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1534578132, // * UNIX timestamp of last checkpoint block
    84,       // * total number of transactions between genesis and last checkpoint
             //   (the tx=... number in the SetBestChain debug.log lines)
    480      // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    0,
    0,
    0};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    0,
    0,
    0};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x73;
        pchMessageStart[1] = 0x61;
        pchMessageStart[2] = 0x72;
        pchMessageStart[3] = 0x6f;
        vAlertPubKey = ParseHex("04a88ea95c9148d71d87f995fa3593ce7e15de1db7cf78efbd01ed2d2cdc3a962fea05b030b4e6ffbfa981236d06efb4bf22eaa5baf68260e70c4446f2c22e0627");


        nDefaultPort = PROTOCOL_P2P_PORT;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // BKZ starting difficulty is 1 / 2^12  //20
        nSubsidyHalvingInterval = 180000;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // BKZ: 1 day
        nTargetSpacing = 3 * 60;  // BKZ: 3 minute
        nLastPOWBlock = 130000;   // BKZ: 6 month 
        nMaturity = 40;  // 2 hours
        nMasternodeCountDrift = 20;
	    nMasternodeColleteralLimxDev = 10000; 
        nModifierUpdateBlock = 1; // we use the version 2 for dmd
        nMaxMoneyOut = 100000000 * COIN;

        const char* pszTimestamp = "Bankitz Community Start 18/08/2018";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("0466317d3a221549c07f74f2621a255cf18d307136bf9e93907bcebe61e829eb8afb78c05706b280fcfdf4775ff208111943fcb621316d48790f6e4201a722e9df") << OP_CHECKSIG;
        // old 049caeb38afaa6465a1fd3b8d8d29ad1a141b4f94f925c9d8a1baab232cfa35319a325cfadd7aa2b5ca717e4117b6cc8b1a88a1e28abbf0668a3a4e7f923aebbfc
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime  = 1534554123;
        genesis.nBits  = 0x1e0ffff0;
        genesis.nNonce = 886886;//3095779;//498585;
		
        /*
new mainnet genesis merkle root: 09f32251ceb8a0d37dc9777686354596e5bf2b5f9d1de71ed00e2f9615cce5bd
new mainnet genesis nonce: 3095779  time:1534172751
new mainnet genesis hash: 00000fc242ea1a7de6af3463a216a655178a8772aec282eddffb372c05798721

new mainnet genesis merkle root: d53fd768da2794312a1c6879b11baa6325be9ab99b43d52a6b09b5017fbb5789
new mainnet genesis nonce: 886886  time:1534554123
new mainnet genesis hash: 000006b9477e087c9b7c1b5b94619a7b4f1616b88a1ca2f0041c438359cf5b8a
     
        hashGenesisBlock = uint256S("0x0");
        if ( genesis.GetHash() !=  hashGenesisBlock)
        {
            printf("\nold mainnet time: %d\n", genesis.nTime);
            printf("old mainnet genesis nonce: %d\n", genesis.nNonce);
            printf("old mainnet genesis hash: %s\n", genesis.GetHash().ToString().c_str());
            printf("old mainnet genesis merkle root: %s\n", genesis.hashMerkleRoot.ToString().c_str());
            
            for(genesis.nNonce == 0; genesis.GetHash() > bnProofOfWorkLimit; genesis.nNonce++){ 
              if(genesis.nNonce%10000==0){
                printf("%d ",genesis.nNonce);  
              }
            } 
            LogPrint("gen:","new mainnet genesis merkle root: %s\n", genesis.hashMerkleRoot.ToString().c_str());
            LogPrint("gen:","new mainnet genesis nonce: %d\n", genesis.nNonce);
            LogPrint("gen:","new mainnet genesis hash: %s\n", genesis.GetHash().ToString().c_str());

            printf("\nnew mainnet genesis merkle root: %s\n", genesis.hashMerkleRoot.ToString().c_str());
            printf("new mainnet genesis nonce: %d  time:%u\n", genesis.nNonce, genesis.nTime);
            printf("new mainnet genesis hash: %s\n", genesis.GetHash().ToString().c_str());
            
            exit(0);
        }
        */
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000006b9477e087c9b7c1b5b94619a7b4f1616b88a1ca2f0041c438359cf5b8a"));
        assert(genesis.hashMerkleRoot == uint256("0xd53fd768da2794312a1c6879b11baa6325be9ab99b43d52a6b09b5017fbb5789"));
       
        vSeeds.push_back(CDNSSeedData("bankitz.network", "seed1.bankitt.network"));
        vSeeds.push_back(CDNSSeedData("bankitz.network", "seed2.bankitt.network"));
	    vSeeds.push_back(CDNSSeedData("bankitz.network", "seed3.bankitt.network"));
	    vSeeds.push_back(CDNSSeedData("bankitz.network", "178.238.236.116"));
       

        //vFixedSeeds.clear();
        //vSeeds.clear();
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,26);
        // Bankitz script addresses start with 'B'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,10);
        // Bankitz private keys start with '7' or 'X'
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,198);
        // Bankitz BIP32 pubkeys start with 'xpub' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        // Bankitz BIP32 prvkeys start with 'xprv' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md 1002	0x800003ea	BKZ	BanKitz
        base58Prefixes[EXT_COIN_TYPE] =  boost::assign::list_of(0x80)(0x00)(0x03)(0xea).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;


        nPoolMaxTransactions = 3;
      
        strSporkKey   = "047e3bf198531c8af0450ab20a91bf521fda24ae7ceadcfed7cf169f2b06867eafa374e7ed92d6a2fc7c4c6cffa2673b45867d245439c922bb697432560ca6d6fe";
        strDarksendPoolDummyAddress = "BW7iibEPmFH6xjKEZTQvamjnGZUNW2zedv";
        nStartMasternodePayments = 1533283754; //dmy 10/08/2018 @ 12:00am (UTC)
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
    
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x73;
        pchMessageStart[1] = 0x61;
        pchMessageStart[2] = 0x72;
        pchMessageStart[3] = 0x6f;
        vAlertPubKey = ParseHex("04a88ea95c9148d71d87f995fa3593ce7e15de1db7cf78efbd01ed2d2cdc3a962fea05b030b4e6ffbfa981236d06efb4bf22eaa5baf68260e70c4446f2c22e0627");


        nDefaultPort = 25448;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // BKZ starting difficulty is 1 / 2^12  //20
        nSubsidyHalvingInterval = 105000;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 60 * 60;  
        nTargetSpacing  = 3 * 60;       
        nLastPOWBlock = 1000;
        nMaturity = 60;
        nMasternodeCountDrift = 20;
	    nMasternodeColleteralLimxDev = 10000; 
        nModifierUpdateBlock = 1; // we use the version 2 for dmd
        nMaxMoneyOut = 100000000 * COIN;

        const char* pszTimestamp = "Bukake Core strat 30/01/2018";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("049caeb38afaa6465a1fd3b8d8d29ad1a141b4f94f925c9d8a1baab232cfa35319a325cfadd7aa2b5ca717e4117b6cc8b1a88a1e28abbf0668a3a4e7f923aebbfc") << OP_CHECKSIG;
        // old 04fcc7102d53be434cb77e13637d5324e0256261f7653281675c564878ce5815bd97be905765394fb099d1763d7f4d88f3857a9ea88b043a8c7d68ca248a1c5f88
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime  = 1533305100;
        genesis.nBits  = 0x1e0ffff0;
        genesis.nNonce = 1696470;
	
        hashGenesisBlock = genesis.GetHash();
        
       // assert(hashGenesisBlock == uint256("0x00000af4b1630e65d8c30cda5478acaa8e2951458a3c51beb50d0045a998c28f"));
       // assert(genesis.hashMerkleRoot == uint256("0x20aec3fb0ff81d2816f1ce40fc8990baa50a1b92ba2b2e80c10f2bc704f6c03d"));
       
        vSeeds.push_back(CDNSSeedData("test.bankitz.network", "192.168.1.58"));
	    vSeeds.push_back(CDNSSeedData("test.bankitz.network", "192.168.1.40"));
        //vFixedSeeds.clear();
        //vSeeds.clear();
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,26);
        // Bankitz script addresses start with '7'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,10);
        // Bankitz private keys start with '7' or 'X'
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,198);
        // Bankitz BIP32 pubkeys start with 'xpub' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        // Bankitz BIP32 prvkeys start with 'xprv' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md 109 	0x8000006d
       // base58Prefixes[EXT_COIN_TYPE] =  boost::assign::list_of(0x80)(0x00)(0x00)(0x6d).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] =  boost::assign::list_of(0x5).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;


        nPoolMaxTransactions = 3;
        //strSporkKey = "049e53e687fdafd78fd42d730fad0e7ea1819396176a2cb85d7a76fa4559cdbd2c2f05330a6f5cbadb44a6c1d324f167e679e9f3e95d9d5649761a3e7f59bf4500";
        strSporkKey   = "047e3bf198531c8af0450ab20a91bf521fda24ae7ceadcfed7cf169f2b06867eafa374e7ed92d6a2fc7c4c6cffa2673b45867d245439c922bb697432560ca6d6fe";
        strDarksendPoolDummyAddress = "AcmpqXViWUXNroqVNYRdKjKrFM6PNa1oTM";
        nStartMasternodePayments = 1533283754; //dmy 10/08/2018 @ 12:00am (UTC)
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x65;
        pchMessageStart[1] = 0x14;
        pchMessageStart[2] = 0x54;
        pchMessageStart[3] = 0x64;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // BKZ: 1 day
        nTargetSpacing = 1 * 60;        // BKZ: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1521022420;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 20622643;
		
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 2264;
        //assert(hashGenesisBlock == uint256("0x00000d024b861dca8bf3b6758c39584c09302c9373cbd8f52e2b2e33f63c017a"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
