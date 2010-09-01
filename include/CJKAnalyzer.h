/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "LuceneContrib.h"
#include "Analyzer.h"

namespace Lucene
{
	/// An {@link Analyzer} that tokenizes text with {@link CJKTokenizer} and filters with {@link StopFilter}
	class LPPAPI CJKAnalyzer : public Analyzer
	{
	public:
	    /// Builds an analyzer with the default stop words: {@link #getDefaultStopSet}.
	    CJKAnalyzer(LuceneVersion::Version matchVersion);
	    
	    /// Builds an analyzer with the given stop words.
	    CJKAnalyzer(LuceneVersion::Version matchVersion, HashSet<String> stopwords);
	    
	    virtual ~CJKAnalyzer();
	
    protected:
        /// Contains the stopwords used with the {@link StopFilter}.
        HashSet<String> stoptable;
        
        LuceneVersion::Version matchVersion;
        
        /// List of typical English stopwords.
        static const wchar_t* _STOP_WORDS[];
    
    public:
        /// Returns an unmodifiable instance of the default stop-words set.
	    static HashSet<String> getDefaultStopSet();
	    
	    /// Creates a {@link TokenStream} which tokenizes all the text in the provided {@link Reader}.
	    ///
	    /// @return A {@link TokenStream} built from {@link CJKTokenizer}, filtered with {@link StopFilter}
	    virtual TokenStreamPtr tokenStream(const String& fieldName, ReaderPtr reader);
	    
	    /// Returns a (possibly reused) {@link TokenStream} which tokenizes all the text  in the 
	    /// provided {@link Reader}.
	    ///
	    /// @return A {@link TokenStream} built from {@link CJKTokenizer}, filtered with {@link StopFilter}
	    virtual TokenStreamPtr reusableTokenStream(const String& fieldName, ReaderPtr reader);
	};
	
	class LPPAPI CJKAnalyzerSavedStreams : public LuceneObject
	{
	public:
	    virtual ~CJKAnalyzerSavedStreams();

    public:
        TokenizerPtr source;
        TokenStreamPtr result;
	};
}